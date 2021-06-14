/*
  Greg Rapp
  ex 6.4
  9/30/2020
*/

#include <stdio.h>
#include <math.h>

double bracketMax(double a, double b, double c);
double fxn(double t);

int main(){
  double a,b,c;
  a = 0;
  b = 5;
  c = 10;
  printf("Max: %lf\n",bracketMax(a,b,c));
}

double fxn(double t){
  double gn,Ne,h,En,Kev,k,m,e1,ut,pi;
  gn = 8;
  En = 10.2;
  e1 = 13.6;
  h = 6.626196e-27;
  Kev = 8.617e-5;
  k = 1.380622e-16;
  m = 9.109558e-28;
  ut = 2.0;
  Ne = 1e14;
  pi = 3.1416;
  return ((gn*Ne*pow(h,3)*exp(-En/(Kev*t)))/(2*pow(2*pi*m*k*t,1.5)*exp(-e1/(Kev*t))+Ne*pow(h,3)*ut));
}
double bracketMax(double a, double b, double c){
  double A,C,x,ya,yb,yc,yx;
  double eps = 1e-5;
  A=a;
  C=c;
  while(fabs(a-c) > eps*fabs(A-C)){
    ya = fxn(a);
    yb = fxn(b);
    yc = fxn(c);
    if(fabs(b-a) < fabs(b-c)){
      x = ((a+b)/(double) 2);
      yx = fxn(x);
      if (yx < yb){
        a = x;
      }
      else if (yx >= yb){
        c = b;
        b = x;
      }
    }
    else if (fabs(b-c) <= fabs(b-a)){
      x = ((b+c)/(double) 2);
      yx = fxn(x);
      if (yx < yb){
        c = x;
      }
      else if (yx >= yb){
        a = b;
        b = x;
      }
    }
  }
  return x;
}
