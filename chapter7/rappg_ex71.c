/*
Greg Rapp
10/19/2020
exercise 7.6
*/
#include <stdio.h>
#include <math.h>
double trapInteg(double xrange[]);
double fxn(double x);
int size;
int main(){
  printf("enter number of points: ");
  scanf("%d",&size);
  double x1 = 1;
  double x2 = 2;
  double xrange[size];
  double a = 1;
  double interval = (x2 - x1)/(double) (size-1);
  for (int i = 0; i < size; i++){
    xrange[i] = a;
    a += interval;
  }
  printf("Calculated Integral: %lf\n",trapInteg(xrange));
}

double trapInteg(double xrange[]){
  double h = xrange[size-1]-xrange[0];
  double sum = 0;
  for (int i = 0; i< size - 1; i++){
    sum += .5 * (xrange[i+1] - xrange[i]) * (fxn(xrange[i+1]) + fxn(xrange[i]));
  }
  return h*sum;
}
double fxn(double x){
  return x*sin(x);
}
