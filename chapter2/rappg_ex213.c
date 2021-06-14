/*
Greg Rapp
EX 2.13
9/9
*/

#include <stdio.h>
#include <math.h>

double computeX(double x);
double computeY(double x, double y);
double computePi(double pi, double x, double y);
int main(){
  double x0 = sqrt(2);
  double pi0 = 2+sqrt(2);
  double y1 = pow(2,.25);
  double x1 = computeX(x0);
  double pi1 = computePi(pi0,x1,y1);
  int i = 1;
  while (fabs(pi0 - pi1) > 1e-8){
    printf("x(%d) = %f y(%d) = %f pi(%d) = %17.15f\n",i,x1,i,y1,i,pi1);
    y1 = computeY(x1,y1);
    x1 = computeX(x1);
    pi0 = pi1;
    pi1 = computePi(pi1,x1,y1);
    i++;
  }
}
double computeX(double x){
  return (0.5*(pow(x,.5)+pow(x,-0.5)));
}
double computeY(double x, double y){
  return ((y*pow(x,0.5)+ pow(x,-0.5))/(y+1));
}
double computePi(double pi, double x, double y){
  return (pi*((x+1)/(y+1)));
}

