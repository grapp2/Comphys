
/*
  Greg Rapp
  9/30/2020
  exercise 5.10
*/
#include <stdio.h>
#include <math.h>
const double pi = 3.1416;
double deg2rad(double theta);
int main(){
  double t0;
  double theta = 60;
  double v0 = 600;
  double g = 9.8;
  double k = 0.005;
  double t1 = 106.0439;
  double eps = 1e-3;
  while (fabs(t1-t0) > eps){
    t0 = t1;
    t1 = (k*v0*sin(deg2rad(theta))+g)/(g*k)*(1-exp(-k*t0));
  }
  printf("T = %lf\n",t1);
}

double deg2rad(double theta){
  return theta * pi/180;
}
