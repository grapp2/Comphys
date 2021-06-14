/*
Greg Rapp
9/23/2020
ex4-4
*/
#include <stdio.h>
#include <math.h>
double deg2rad(double a);
double rad2deg(double a);
double linearInterp(double x0,double x1,double y0, double y1,double x);
const double pi = 3.14159265359;
const double e = 1e-7;
int main(){
  double x1,x2,xf,theta2;
  double x0 = 0;
  double theta0 = 45;
  double theta1 = 5;

  theta0 = deg2rad(theta0);
  theta1 = deg2rad(theta1);
  x1 = tan(pi-theta1-(pi/2+theta1));
  printf("Enter final position: ");
  scanf("%lf",&xf);

  while(fabs(xf-x2)>e){
    while(theta0 > pi/2.0) theta0 -= pi/2.0;
    while(theta1 > pi/2.0) theta1 -= pi/2.0;
    while(theta0 < 0) theta0 += pi/2.0;
    while(theta1 < 0) theta1 += pi/2.0;
    theta2 = theta0+((theta1-theta0)/(x1-x0))*(xf-x0);
    x2 = tan(pi-theta2-(pi/2+theta2));
    x0 = x1;
    x1 = x2;
    theta0 = theta1;
    theta1 = theta2;
  }
  printf("Calculated angle: %lf degrees\n", rad2deg(theta2));
  return 0;
}

double deg2rad(double a){
  return (a*pi/180);
}
double rad2deg(double a){
  return (a*180/pi);
}
