
/*
  Greg Rapp
  9/30/2020
  exercise 5.7
*/
#include <stdio.h>
#include <math.h>
double fxn(double t);
double dfxn(double t);
double newtRaphMeth( double targety);

const double eps = 1e-6;

int main(){
  double y,x;
  y = 20.1;
  x= newtRaphMeth(y);
  printf("Temperature of air at 20.1uPa: %lfK\n",x);
}

double newtRaphMeth(double targety){
  double x0,x1;
  x1 = 200;
  while (fabs(x1-x0) > eps){
    x0 = x1;
    x1 = x0 - (fxn(x0)-targety)/dfxn(x0);
  }
  return x1;
}
double fxn(double t){
  return 3.61111e-8*pow(t,3) - 6.95238e-5*pow(t,2) + 0.0805437 * t - 0.3;
}
double dfxn(double t){
  return 3*3.61111e-8*pow(t,2)- 2*6.95238e-5*t + 0.0805437;
}
