/*
  Greg Rapp
  8/7/2020
  exercise 6.8
*/
#include <stdio.h>
#include <math.h>
double dfxn(double t,double w);
double findMin(double t);
int main(){
  printf("2000: %lf, 5000: %lf, 8000: %lf, 11000: %lf, 14000: %lf\n",findMin(2000),findMin(5000),findMin(8000),findMin(11000),findMin(14000));
  return 0;
}

double findMin(double t){
  double a,b,c,x1,x2,dya,dyb,dyc,yx;
  double eps = 1e-7;
  //I do not understand how to find the values for a, b, and c.
  a = 11;
  b = 15;
  c = 20;
  x2= 10;
  while(fabs(x2-x1) > eps){
    printf("A: %lf\tB: %lf\tC: %lf\tX: %lf\n",a,b,c,x2);
    x1 = x2;
    dya = dfxn(t,a);
    dyb = dfxn(t,b);
    dyc = dfxn(t,c);
    if(dfxn(t,b) < 0){
      x2 = a - ((dya * (b-a))/(dyb - dya));
      a = b;
      b = x2;
    }
    else if(dfxn(t,b) > 0){
      x2 = b - ((dyb * (c-b))/(dyc -dyb));
      c = b;
      b = x2;
    }
    else break;
  }
}

double dfxn(double t, double w){  // derivative of planck function
  return 1.7136852174e35*exp(1.43879e8/(w*t))/(pow(w,6)*pow(t,2)*(pow(exp(1.43879000/(w*t))-1,2)));
}





