/*
  Greg Rapp
  9/30/2020
  exercise 5.3
*/
#include <stdio.h>
#include <math.h>
double fxn(double t);
double findX(double a0, double b0, double targety);

const double e = 1e-6;

int main(){
  double n;
  double a = 100;
  double b = 600;
  double targety = 20.1;
  n = findX(a,b,targety);
  printf("Temperature of air at 20.1uPa: %lfK\n",n);
}
double findX(double a0, double b0, double targety){
  double y,x0,x1,a1,b1;
  a1 = a0;
  b1 = b0;
  x1 = 10;
  while(fabs(x1-x0) > e){
    x0 = x1;
    x1 = (b1+a1)/(double) 2;
    y = fxn(x1);
    if(y > targety){
      b1 = x1;
    }
    else if(y < targety){
      a1 = x1;
    }
    else break;
  }
  return x1;
}
double fxn(double t){
  return 3.61111e-8*pow(t,3) - 6.95238e-5*pow(t,2) + 0.0805437 * t - 0.3;
}
