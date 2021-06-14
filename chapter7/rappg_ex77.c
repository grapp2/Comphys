/*
Greg Rapp
10/19/2020
exercise 7.7
*/
#include <stdio.h>
#include <math.h>

double gaussIntegrate(double a, double b);
double fxn(double x);

int main(){
  printf("Calculated Integral: %lf\n",gaussIntegrate(1,2));
}

double gaussIntegrate(double a, double b){
  double w;
  double res = 0;
  double x[5];
  x[0] = -.90618;
  x[1] = -.538469;
  x[2] = 0;
  x[3] = .538469;
  x[4] = .90618;
  for (int i = 0; i < 5; i++){
    if (i == 0 || i == 4) w = .236927;
    else if (i == 1 || i == 3) w = .478629;
    else w = .568889;
    res+= w*fxn((a+b)/2.0 + (b-a)/2.0*x[i]);
  }
  return res * (b-a)/2.0;
}
double fxn(double x){
  return x*sin(x);
}

