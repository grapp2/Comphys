/*
  Greg Rapp
  8/7/2020
  exercies 6.12
*/
#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"
float f(float x[]);
const float pi = 3.14159;
float e1,e2;
int main()
{
  float *p,**xi,fret;
  int iter=0;
  int i,j;
  float x0,y0;
  /* Allocate memory for the p vector and the xi matrix */
  p = vector(1,2);
  xi = matrix(1,2,1,2);
  printf("enter value for e1 between 0 and 0.5: ");
  scanf("%f",&e1);
  while(e1 > 0.5 || e1 < 0){
    printf("incorrect value\nenter value for e1 between 0 and 0.5: ");
    scanf("%f",&e1);
  }
  e2 = e1-1;
  /* initial point */
  x0 = -cos(60*pi/180);
  y0 = sin(60*pi/180);
  p[1] = x0;
  p[2] = y0;
  /* Initial directions */
  for(i=1;i<=2;i++) {
    for(j=1;j<=2;j++) {
      if(i == j) xi[i][j] = 1.0;
      else xi[i][j] = 0.0;
    }
  }
  /* invoke powell with ftol = 0.001 */
  powell(p,xi,2,0.001,&iter,&fret,f);
  printf("\nThe minimum is found at x = %f, y = %f",p[1],p[2]);
  printf("\nThe value of f at the minimum is %f\n",fret);
  return(0);
}

/* here is our function that we want to miminize */
float f(float x[])
{
  float term1, term2, term3,v;
  term1 = e2/(sqrt((x[1]-e1)*(x[1]-e1)+x[2]*x[2]));
  term2 = e1/(sqrt((x[1]-e2)*(x[1]-e2)+x[2]*x[2]));
  term3 = .5*(x[1]*x[1]+x[2]*x[2]);
  v = -1*(term1 - term2 - term3);
  /* print out intermediate values so we can see what is happening */
  printf("\nv = %f",x[1],x[2],v);
  return(v);
}

