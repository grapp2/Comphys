#include <stdio.h>
#include <math.h>
int main(){
  double t = 0;
  double x;
  double y;
  while (t <= 5){
    x = 5+0.12*pow(t,2);
    y = 0.02*pow(t,3);
    printf("t = %3.1lf x = %3.1lf y = %3.1lf\n",t,x,y);
    t = t + 0.5;
    //test change 2
    //test changes
  }
}
