/*
Greg Rapp
10/19/2020
exercise 7.2
*/
#include <stdio.h>
#include <math.h>
double trapInteg(double xrange[]);
double fxn(double x);
double integrandfxn(double x);
int size;
int main(){
  printf("enter number of points: ");
  scanf("%d",&size);
  double x1 = 298;
  double x2 = 500;
  double xrange[size];
  double a = x1;
  double interval = (x2 - x1)/(double) size;
  for (int i = 0; i < size; i++){
    xrange[i] = a;
    a += interval;
  }
  printf("Calculated Integral: %lf\n",trapInteg(xrange));
}

double trapInteg(double xrange[]){
  double h = (xrange[size-1]-xrange[0])/(double) (size-1);
  double sum = 0;
  int i;
  for (i = 0; i < size - 1; i++){
    sum += .5 * (xrange[i+1] - xrange[i]) * (integrandfxn(xrange[i+1]) + integrandfxn(xrange[i]));
  } // Gray says I'm multiplying by h twice
  return h*sum;
}
double fxn(double x){
  double a = 16.86;
  double b = 4.77e-3;
  double c = 8.54e5;
  return a+(b*x)-(c/pow(x,2));
}
double integrandfxn(double x){
  double cap;
  cap = fxn(x);
  return cap/x;
}
