/*
Greg Rapp
10/19/2020
exercise 7.8
*/
#include <stdio.h>
#include <math.h>

double gaussIntegrate(double a, double b);
double fxn(double x);
double integrandfxn(double x);

int main(){
  printf("Calculated Integral: %lf\n",gaussIntegrate(298,500));
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
    res+= w*integrandfxn((a+b)/2.0 + (b-a)/2.0*x[i]);
  }
  return res * (b-a)/2.0;
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


