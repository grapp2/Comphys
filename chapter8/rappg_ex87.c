/*
  Greg Rapp
  11/4/2020
  exercise 8.7
*/

#include <stdio.h>
#include <math.h>
double yfunc(double x);
double yderiv(double x);
/* Implements the Adams-Bashforth-Moulton routine y(0) = 1*/
int n = 3;
int main()
{
  double xm2,xm1,x0,x1,ym2,ym1,y0,y1;
  double ypm2,ypm1,yp0,yp1;
  double dx = 0.1;
  /* Prime the Pump! */
  ym2 = yfunc(0.0);
  ypm2 = yderiv(0.0);
  ym1 = yfunc(0.1);
  ypm1 = yderiv(0.1);
  y0 = yfunc(0.2);
  yp0 = yderiv(0.2);
  xm2 = 0.0;
  xm1 = 0.1;
  x0 = 0.2;
  x1 = 0.3;
  printf("x = %3.1f y = %f\n",xm2,ym2);
  printf("x = %3.1f y = %f\n",xm1,ym1);
  printf("x = %3.1f y = %f\n",x0,y0);
  while(x1 < 1) {
    /* Predictor step */
    y1 = y0 + (23.0*yp0 - 16.0*ypm1 + 5.0*ypm2)*dx/12.0;
    /* Calculate yp1 */
    yp1 = (2/x1*yderiv(x1)+pow(y1,n));
    /* Corrector step */
    y1 = y0 + (5.0*yp1 + 8*yp0 - ypm1)*dx/12.0;
    printf("x = %3.1f y = %f\n",x1,y1);
    if(x1 == 1.0) break;
    /* Update variables */
    xm2 += dx;
    xm1 += dx;
    x0 += dx;
    x1 += dx;
    ym2 = ym1;
    ym1 = y0;
    y0 = y1;
    ypm2 = ypm1;
    ypm1 = yp0;
    yp0 = yp1;
  }
  return(0);
}

double yfunc(double x)
{
  return(1-(x*x/(double)6)+((n*x*x*x*x)/(double)120) + (5*n-8*n*n)*(x*x*x*x*x*x)/(double)15120);
}
double yderiv(double x)
{
  // used wolfram alpha to compute derivative
  return(x*(-840 + x*x*(84*n + x*x*n*(5-8*n))))/(double) 2520;
}
