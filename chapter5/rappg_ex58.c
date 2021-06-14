
/*
  Greg Rapp
  9/30/2020
  exercise 5.8
*/
#include <stdio.h>
#include <math.h>
double fxn(double n0, double t);
double dfxn(double n0, double t);
double newtRaphMeth(double n0,double targety);

const double eps = 1e-6;

int main(){
  double y,x;
  double n0 = 100;
  y = n0/2;
  x= newtRaphMeth(n0,y);
  printf("Calculated Half Life: %lfs\n",x);
}

double newtRaphMeth(double n0, double targety){
  double x0,x1;
  // If you initialize x1 to be too large the function won't converge
  x1 = 1;
  while (fabs(x1-x0) > eps){
    x0 = x1;
    x1 = x0 - (fxn(n0,x0)-targety)/dfxn(n0,x0);
  }
  return x1;
}
double fxn(double n0, double t){
  double tau1 = 5.697;
  double tau2 = 9.446;
  return n0 / (double) 2 * (exp(-t/tau1) + exp(-t/tau2));
}
double dfxn(double n0, double t){
  double tau1 = 5.697;
  double tau2 = 9.446;
  return n0 / (double) 2 * ((-exp(-t/tau1)/tau1 - exp(-t/tau2)/tau2));
}


