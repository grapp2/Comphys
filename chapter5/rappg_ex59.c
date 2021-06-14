
/*
  Greg Rapp
  9/30/2020
  exercise 5.9
*/
#include <stdio.h>
#include "comphys.c"
#include "comphys.h"

double newtRaphMeth(double start,double targety);

const double eps = 1e-6;

int main(){
  double first_root,second_root, targety;
  targety = 0;
  // to find what values to use as "start" I plotted the function in gnuplot.
  first_root = newtRaphMeth(1,targety);
  second_root = newtRaphMeth(5,targety);
  printf("first root: %lf\nsecond root: %lf\n",first_root,second_root);
}

double newtRaphMeth(double start,double targety){
  float x0,x1;
  x1 = start;
  while (fabs(x1-x0) > eps){
    x0 = x1;
    x1 = x0 - (bessj0(x0)-targety)/-bessj1(x0);
  }
  return x1;
}
