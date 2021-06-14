/*
  Greg Rapp
  8/7/2020
  exercise 6.5
*/
#include <stdio.h>
#include <math.h>
double dfxn(double x);

int main(){
  double a,b,c,x1,x2,dya,dyb,dyc,yx;
  double eps = 1e-7;
  a = 11;
  b = 15;
  c = 20;
  x2= 10;
  while(fabs(x2-x1) > eps){
    printf("A: %lf\tB: %lf\tC: %lf\tX: %lf\n",a,b,c,x2);
    x1 = x2;
    dya = dfxn(a);
    dyb = dfxn(b);
    dyc = dfxn(c);
    if(dfxn(b) < 0){
      x2 = a - ((dya * (b-a))/(dyb - dya));
      a = b;
      b = x2;
    }
    else if(dfxn(b) > 0){
      x2 = b - ((dyb * (c-b))/(dyc -dyb));
      c = b;
      b = x2;
    }
    else break;
  }
}
double dfxn(double x){
  return 3.0 * pow(x,2) - 48.0 * x + 6.0;
}
