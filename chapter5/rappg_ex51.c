#include <stdio.h>
#include <math.h>
double findRoot(double a0, double b0);
double fxn(double x);
const double e = 1e-6;

int main(){
  double a,b,ans;
  printf("Enter initial interval: ");
  scanf("%lf,%lf",&a,&b);
  ans = findRoot(a,b);
  printf("Root found at x = %lf\n",ans);
}

double findRoot(double a0, double b0){
  double y,x0,x1,a1,b1;
  a1 = a0;
  b1 = b0;
  x1 = 10;
  while(fabs(x1-x0) > e){
    x0 = x1;
    x1 = (b1+a1)/(double) 2;
    y = fxn(x1);
    if(y > 0){
      b1 = x1;
    }
    else if(y < 0){
      a1 = x1;
    }
    else break;
  }
  return x1;
}

double fxn(double x){
  return 5*pow(x,2)+9*x-80;
}
