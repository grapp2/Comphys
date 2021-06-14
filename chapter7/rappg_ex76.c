/*
Greg Rapp
10/19/2020
exercise 7.6
*/

#include <stdio.h>
#include <math.h>

float simpsons(float x1, float x3, int n);
double fxn(double x, double T);

double pi = 3.14159265359;
double c = 2.99792458e8;
double h = 6.62606957e-34;
double k = 1.3806488e-23;

int main(){
  int n;
  float x1 = 1e-9;
  float x3 = 1e-4;
  printf("enter number of points: ");
  scanf("%d",&n);
  printf("Calculated Integral: %lf\n",2*pi*h*c*c*simpsons(x1,x3,n));
}

float simpsons(float x1, float x3, int n){
  //switch this value for different temperatures...
  float T = 3000;
  float sum = 0;
  float a = (x3-x1)/(float) n;
  float x[n],y[n];
  float interval = (x3-x1)/(float) (n-1);
  for (int i = 0; i < n; i++){
    x[i] = x1 + i * interval;
    y[i] = fxn(x[i],T);
  }
  for (int i = 0; i < n; i++){
    if (i == 0 || i == n-1){
      sum += y[i];
    }
    else if (i % 2 == 1){
      sum += y[i]*4;
    }
    else if (i % 2 == 0){
      sum += y[i]*2;
    }
  }
  return sum * (a/(float)3);
}
double fxn(double x, double T){
  return 1/(pow(x,5)*(exp(h*c/(x*k*T))-1));
}


