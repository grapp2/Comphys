/*
  Greg Rapp
  8/7/2020
  exercies 6.9
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
  float **p,*y;
  int nfunk,i;
  float A,gam,B,C;
  A = 10.1;
  B = 3;
  C = .5;
  gam = .2;
  FILE *in;
  p = matrix(1,5,1,4);
  y = vector(1,5);
  t = vector(0,200);
  yi = vector(0,200);
  if((in = fopen("decay.out","r")) == NULL) {
    printf("\nCannot find input file\n");
    exit(1);
  }
  k = 0;
  while(fscanf(in,"%f %f",&t[k],&yi[k]) != EOF) k++;
  fclose(in);
  p[1][1] = A;
  p[1][2] = gam;
  p[1][3] = B;
  p[1][4] = C;
  p[2][1] = A + 1;
  p[2][2] = gam;
  p[2][3] = B;
  p[2][4] = C;
  p[3][1] = A;
  p[3][2] = gam + 0.1;
  p[3][3] = B;
  p[3][4] = C;
  p[4][1] = A;
  p[4][2] = gam;
  p[4][3] = B + .5;
  p[4][4] = C;
  p[5][1] = A;
  p[5][2] = gam;
  p[5][3] = B;
  p[5][4] = C + .1;

  for(int i = 1; i <= 5; i++) y[i] = f(p[i]);

  amoeba(p,y,4,0.001,f,&nfunk);

  A = (p[1][1]+p[2][1]+p[3][1]+p[4][1]+p[5][1])/5.0;
  gam = (p[1][2]+p[2][2]+p[3][2]+p[4][2]+p[5][2])/5.0;
  B = (p[1][3]+p[2][3]+p[3][3]+p[4][3]+p[5][3])/5.0;
  C = (p[1][4]+p[2][4]+p[3][4]+p[4][4]+p[5][4])/5.0;
  printf("\nThe minimum is found at A = %f, gamma = %f, B = %f, C = %f\n",A,gam,B,C);
  printf("The number of function evaluations is %d\n",nfunk);
  return(0);
}
//chi squared should = 24.822 a = 10.059 gam = .213 b = 3.23 c = .553 - not exactly
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
