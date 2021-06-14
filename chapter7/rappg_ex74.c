/*
Greg Rapp
10/19/2020
exercise 7.4
*/
#include <stdio.h>
#include <math.h>

float simpsons(float x1, float x3, int n);
double fxn(double x);
double integrandfxn(double x);

int main(){
  int n;
  float x1 = 298;
  float x3 = 500;
  printf("enter number of points: ");
  scanf("%d",&n);
  printf("Calculated Integral: %lf\n",simpsons(x1,x3,n));
}

float simpsons(float x1, float x3, int n){
  float sum = 0;
  float h = (x3-x1)/(float) (n-1);
  float x[n+1],y[n+1];

  for (int i = 0; i < n; i++){
    x[i] = x1 + i * h;
    y[i] = integrandfxn(x[i]);
  }
  for (int i = 0; i < n; i++){
    if (i == 0 || i == n){
      sum += y[i];
    }
    else if (i % 2 == 1){
      sum += y[i]*4;
    }
    else if (i % 2 == 0){
      sum += y[i]*2;
    }
  }
  return sum * (h/(float)3);
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


