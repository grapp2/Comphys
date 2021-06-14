/*
  Greg Rapp
  11/11/2020
  exercise 9.5
*/
#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"
float X1(float x);
float X2(float x);
float X3(float x);
float X4(float x);

float pi = 3.141592654;
int main()
{
  float *x, *y;
  float **A, **b;
  float chi2, dev, *sa;
  int M,N,i,j,k,l;
  FILE *in;
  M = 4;
  float (*X[4])(float) = {X1,X2,X3,X4};
  A = matrix(1,M,1,M);
  b = matrix(1,M,1,1);
  x = vector(1,100);
  y = vector(1,100);
  sa = vector(1,M);

  for (j = 1; j <= M; j++){
    b[j][1] = 0;
    for (k = 1; k <= M; k++) A[j][k] = 0;
  }
  if ((in = fopen("data95.dat","r")) == NULL){
    printf("cannot open file\n");
    exit(1);
  }
  l = 1;
  while (fscanf(in, "%f %f", &x[l], &y[l]) != EOF){
    for (k = 1; k <= M; k++){
      b[k][1] += y[l] * X[k-1](x[l]);
      for (j = 1; j <= M; j++){
        A[k][j] += X[j-1](x[l]) * X[k-1](x[l]);
      }
    }
    l++;
  }
  N = l-1;
  gaussj(A,M,b,1);

  chi2 = 0;
  for (i = 1; i <= N; i++){
    dev = y[i];
    for (k = 1; k <= M; k++) dev += -b[k][1] * X[k-1](x[i]);
    chi2 += dev*dev;
  }

  for (k = 1; k <= M; k++) sa[k] = sqrt((chi2*A[k][k])/(float)(N-M));
  printf("chi2 = %e\n",chi2);
  for (k = 1; k <= M; k++) printf("a[%d] = %f +/- %f\n",k, b[k][1], sa[k]);
  return(0);
}
float X1(float x)
{
  return(1);
}
float X2(float x)
{
  return(sin(pi*x));
}
float X3(float x)
{
  return(sin(2*pi*x));
}
float X4(float x){
  return (sin(3*pi*x));
}
