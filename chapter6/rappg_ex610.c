/*
  Greg Rapp
  8/7/2020
  exercies 6.10
*/
#include <stdio.h>
#include <math.h>
#include "comphys.h"
#include "comphys.c"
const float pi = 3.14159;

float f(float x[]);
float e1,e2;

int main()
{
  float **p,*y;
  int nfunk,i;
  float x0,y0;
  /* Allocate memory for the p matrix and the y vector */
  p = matrix(1,3,1,2);
  y = vector(1,3);
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
  /* define the vertices of the simplex - in this case a triangle */
  p[1][1] = x0;
  p[1][2] = y0;
  p[2][1] = x0 + .01;
  p[2][2] = y0;
  p[3][1] = x0;
  p[3][2] = y0 + .01;
  /* initiate y[i] */
  for(i=1;i<=3;i++) y[i] = f(p[i]);
  /* invoke amoeba with ftol = 0.001 */
  amoeba(p,y,2,0.001,f,&nfunk);
  /* the best value for the minimum is obtained by averaging the final
  p’s. */
  x0 = (p[1][1]+p[2][1]+p[3][1])/3.0;
  y0 = (p[1][2]+p[2][2]+p[3][2])/3.0;
  printf("\nThe minimum L4 is found at x0 = %f, y0 = %f\n",x0,y0);
  printf("The number of function evaluations is %d\n",nfunk);
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
