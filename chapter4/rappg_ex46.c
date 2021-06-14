/*
Greg Rapp
9/23/2020
ex4-6
*/
#include <stdio.h>
double linearInterp(double xn[],double yn[],double x);

double t[] = {32.88,45.82,53.98,60.07,64.98,69.11,72.70,75.88,78.74,81.34,83.73,85.95,88.02,89.96,91.78,93.51,95.15,96.71,96.87,97.02,97.17,97.32,97.47,97.62,97.76, 97.91, 98.06, 98.21, 98.35, 98.5, 98.64, 98.78, 98.93, 99.07, 99.21, 99.35, 99.49, 99.63, 99.77,99.91,100.05,100.19,100.32,100.46,100.60,100.73,100.87,101.00,101.14,101.27,101.40,101.54,101.67,101.80,101.93,102.06,102.19,102.32,103.59,104.81,105.99,107.14,108.25,109.32,110.36,111.38,112.37,113.33,114.26,115.18,116.07,116.94,117.79,118.63,119.44,120.24,121.02,121.79,122.54};
int main(){
  int data = 50;
  int count = 0;
  double p[78];
  double x;
  double y;
  while (data < 900){
    p[count] = data;
    count++;
    data = data + 50;
  }
  while (data < 1100){
    p[count] = data;
    count++;
    data = data + 5;
  }
  while (data < 2200){
    p[count] = data;
    count++;
    data = data + 50;
  }
  printf("Enter pressure: ");
  scanf("%lf",&x);
  if(x < 50 || x > 2150){
    printf("Pressure out of range\n");
  }
  else{
    y = linearInterp(p,t,x);
    printf("Calculated temperature: %lf\n",y);
  }
  return 0;
}

double linearInterp(double xn[],double yn[],double x){
  double x1,x2,x3,x4,y1,y2,y3,y4,y,term1,term2,term3,term4;
  int size = 79;
  int j;
  for(int i=0;i<size;i++) {
    if(xn[i] <= x && xn[i+1] >= x) {
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
