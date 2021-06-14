/*
Greg Rapp
10/19/2020
exercise 7.3
*/
#include <stdio.h>
#include <math.h>

float simpsons(float x1, float x3, int n);
float fxn(float x);

int main(){
  int n;
  float x1 = 1;
  float x3 = 2;
  printf("enter number of points: ");
  scanf("%d",&n);
  printf("Calculated Integral: %lf\n",simpsons(x1,x3,n));
}

float simpsons(float x1, float x3, int n){
  float sum = 0;
  float h = (x3-x1)/(float) (n-1);
  float x[n],y[n];
  for (int i = 0; i < n; i++){
    x[i] = x1 + i * h;
    y[i] = fxn(x[i]);
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
  return sum * (h/(float)3);
}
float fxn(float x){
  return x*sin(x);
}

