#include <stdio.h>

const double g = -9.8;

int main()
{
  double v0;
  double tf;
  printf("Enter velocity and final time: ");
  scanf("%lf,%lf",&v0,&tf);
  double v = findFinalVelocity(v0, tf);
  printf("Final velocity = %lf\n", v);
  
}
