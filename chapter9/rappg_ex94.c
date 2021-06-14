/*
  Greg Rapp
  11/11/2020
  exercise 9.4
*/
#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"

int main(){
  float *x, *y;
  float **A, **b;
  float chi2, dev, *sa;
  int m,M,N,i,j,k,l;
  FILE *in;
  printf("Input degree of polynomial > ");
  scanf("%d", &m);
  M = m+1;
  A = matrix(1,M,1,M);
  b = matrix(1,M,1,1);
  x = vector(1,60);
  y = vector(1,60);
  sa = vector(1,M);
  for (j = 1; j <= M; j++){
    b[j][1] = 0;
    for (k = 1; k <= M; k++){
      A[j][k] = 0;
    }
  }
  if ((in = fopen("data94.dat","r")) == NULL){
    printf("cannot open file\n");
    exit(1);
  }
  l = 1;
  while (fscanf(in, "%f %f", &x[l], &y[l]) != EOF){
    for (k = 1; k <= M; k++){
      b[k][1] += y[l] * pow(x[l],(double) (k-1));
      for (j = 1; j <= M; j++){
        A[k][j] += pow(x[l], (double) (j-1)) * pow(x[l], (double) (k-1));
      }
    }
    l++;
  }

  N = l-1;
  gaussj(A,M,b,1);

  chi2 = 0;
  for (i = 1; i <= N; i++){
    dev = y[i];
    for (k = 1; k <= M; k++){
      dev += -b[k][1] * pow(x[i], (double) (k - 1));
    }
    chi2 += dev*dev;
  }
  for (k = 1; k <= M; k++){
    sa[k] = sqrt((chi2*A[k][k])/(float)(N-M));
  }
  printf("chi2 = %e\n",chi2);
  for (k = 1; k <= M; k++){
    printf("a[%d] = %f +/- %f\n",k, b[k][1], sa[k]);
  }
}
