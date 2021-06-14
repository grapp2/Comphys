
/*
  Greg Rapp
  9/30/2020
  exercise 6.1
*/
#include <stdio.h>
#include <math.h>
double fxn(double x);

int main(){
  double a,b,c,A,C,x,ya,yb,yc,yx;
  double eps = 1e-7;
  a = 11;
  b = 15;
  c = 20;
  A=a;
  C=c;
  while(fabs(a-c) > eps*fabs(A-C)){
    printf("A: %lf\tB: %lf\tC: %lf\tX: %lf\n",a,b,c,x);
    ya = fxn(a);
    yb = fxn(b);
    yc = fxn(c);
    if(fabs(b-a) > fabs(b-c)){
      x = ((a+b)/(double) 2);
      yx = fxn(x);
      if (yx > yb){
	a = x;
      }
      else if (yx <= yb){
	c = b;
	b = x;
      }
    }
    else if (fabs(b-c) >= fabs(b-a)){
      x = ((b+c)/(double) 2);
      yx = fxn(x);
      if (yx > yb){
        c = x;
      }
      else if (yx <= yb){
        a = b;
        b = x;
      }
    }
  }
}

double fxn(double x){
  return pow(x,3)-24.0*pow(x,2)+6.0*x+15.0;
}
