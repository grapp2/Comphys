/*
Greg Rapp
10/19/2020
exercise 7.5
*/
#include <stdio.h>
#include <math.h>
double trapInteg(double x1,double x2, int n);
double fxn(double x);
int main(){
  double b,m,ans1,ans2,x3,x4;
  double x1 = 1;
  double x2 = 2;
  ans1 = trapInteg(x1,x2,30);
  ans2 = trapInteg(x1,x2,80);
  x3 = 1/(double)(30*30);
  x4 = 1/(double)(80*80);
  m = (ans2-ans1)/(x4-x3);
  b = ans2-x4*m;
  printf("Calculated Integral: %lf\n",b);
}

double trapInteg(double x1,double x2, int n){
  double xrange[n];
  double a = x1;
  double interval = (x2 - x1)/(double) (n-1);
  for (int i = 0; i < n; i++){
    xrange[i] = a;
    a += interval;
  }
  double h = xrange[n-1]-xrange[0];
  double sum = 0;
  for (int i = 0; i< n - 1; i++){
    sum += .5 * (xrange[i+1] - xrange[i]) * (fxn(xrange[i+1]) + fxn(xrange[i]));
  }
  return h*sum;
}
double fxn(double x){
  return x*sin(x);
}



