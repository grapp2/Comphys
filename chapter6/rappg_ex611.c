/*
  Greg Rapp
  8/7/2020
  exercies 6.11
*/
#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"
float *t,*yi;
int k;
float f(float x[]);
int main()
{
  FILE *in;
  float *p,**xi,*y,fret;
  int iter=0;
  int i,j;
  float A,B,C,gam;
  /* Allocate memory for the p vector and the xi matrix */
  p = vector(1,4);
  xi = matrix(1,4,1,4);
  y = vector(1,5);
  t = vector(0,200);
  yi = vector(0,200);
  if((in = fopen("decay.out","r")) == NULL) {
    printf("\nCannot find input file\n");
    exit(1);
  }
  k = 0;
  while(fscanf(in,"%f %f",&t[k],&yi[k]) != EOF) k++;
  /* initial point */
  A = 10.1;
  B = 3.5;
  C = .5;
  gam = .2;
  p[1] = A;
  p[2] = gam;
  p[3] = B;
  p[4] = C;
  /* Initial directions */
  for(i=1;i<=4;i++) {
    for(j=1;j<=4;j++) {
      if(i == j) xi[i][j] = 1;
      else xi[i][j] = 0.0;
    }
  }
  /* invoke powell with ftol = 0.001 */
  powell(p,xi,4,0.001,&iter,&fret,f);
  printf("\nThe minimum is found at A = %f, B = %f, C = %f, gam = %f",p[1],p[2],p[3],p[4]);
  printf("\nThe value of f at the minimum is %f\n",fret);
  return(0);
}

float f(float x[])
{
  float y1,chi2;
  int i;
  chi2 = 0.0;
  for(i=0;i<k;i++) {
    y1 = x[1]*exp(-x[2]*t[i])*sin(x[3]*t[i] + x[4]);
    chi2 += (y1 - yi[i])*(y1 - yi[i]);
  }
  printf("\nchi2 = %f",chi2);
  return(chi2);
}
