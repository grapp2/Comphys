/*
  Greg Rapp
  9/30/2020
  ex 5.4
*/
#include <stdio.h>
#include <math.h>
double findY(double a0, double b0, double yi);
double lagrangeInterp(double xn[],double yn[],double x);

double xin[] = {6.4,6.5,6.6,6.7,6.8,6.9,7.0,7.1,7.2,7.3};
double yin[] = {.022718,.017866,.013162,.008598,.004168,-.000134,-.004312,-.008373,-.012321,-.016161};
const double e = 1e-4;

int main(){
  double targety, result;
  double x0 = 0;
  double a = 0;
  double b = 1;
  targety = lagrangeInterp(xin,yin,x0);
  result = findY(a,b,targety);
  printf("X value at the surface of the star: %lf\n",result);
}

double findY(double a0, double b0, double yi){
  double y,x0,x1,a1,b1;
  a1 = a0;
  b1 = b0;
  x1 = 10;
  while(fabs(x1-x0) > e){
    x0 = x1;
    x1 = (b1+a1)/(double) 2;
    y = lagrangeInterp(xin,yin,x1);
    if(y > yi){
      b1 = x1;
    }
    else if(y < yi){
      a1 = x1;
    }
    else break;
  }
  return x1;
}

double lagrangeInterp(double xn[],double yn[],double x){
  double x1,x2,x3,x4,y1,y2,y3,y4,y,term1,term2,term3,term4;
  int size = 10;
  int j;
  for(int i=0;i<size;i++) {
    if(xn[i] < x && xn[i+1] >= x) {
      j = i;
      break;
    }
  }
  if (j == 0){
    x1 = xn[j];
    x2 = xn[j+1];
    x3 = xn[j+2];
    x4 = xn[j+3];
    y1 = yn[j];
    y2 = yn[j+1];
    y3 = yn[j+2];
    y4 = yn[j+3];
  }
  else if (j == size-2){
    x1 = xn[j-2];
    x2 = xn[j-1];
    x3 = xn[j];
    x4 = xn[j+1];
    y1 = yn[j-2];
    y2 = yn[j-1];
    y3 = yn[j];
    y4 = yn[j+1];
  }
  else if (j == size-1){
    x1 = xn[j-3];
    x2 = xn[j-2];
    x3 = xn[j-1];
    x4 = xn[j];
    y1 = yn[j-3];
    y2 = yn[j-2];
    y3 = yn[j-1];
    y4 = yn[j];
  }
  else{
    x1 = xn[j-1];
    x2 = xn[j];
    x3 = xn[j+1];
    x4 = xn[j+2];
    y1 = yn[j-1];
    y2 = yn[j];
    y3 = yn[j+1];
    y4 = yn[j+2];
  }
  term1 = ((x-x2)*(x-x3)*(x-x4))/((x1-x2)*(x1-x3)*(x1-x4))*y1;
  term2 = ((x-x1)*(x-x3)*(x-x4))/((x2-x1)*(x2-x3)*(x2-x4))*y2;
  term3 = ((x-x1)*(x-x2)*(x-x4))/((x3-x1)*(x3-x2)*(x3-x4))*y3;
  term4 = ((x-x1)*(x-x2)*(x-x3))/((x4-x1)*(x4-x2)*(x4-x3))*y4;
  y = term1+term2+term3+term4;
  return y;
}
