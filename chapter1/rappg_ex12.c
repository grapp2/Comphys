#include <stdio.h>


int main()
{
  double v0;
  double tf;
  printf("Enter velocity and final time: ");
  scanf("%lf,%lf",&v0,&tf);
  double v = findFinalVelocity(v0, tf);
  printf("Final velocity = %lf\n", v);
  // chan
  printf("Final velocity = %lf\n", v);  
}
