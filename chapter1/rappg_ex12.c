#include <stdio.h>

const double g = -9.8;
double findFinalVelocity(double v0, double tf)
{
  double ans;
  ans = v0 + g*tf;
  return ans;
}
int main()
{
  double v0;
  double tf;

  printf("Enter velocity and final time: ");

  scanf("%lf,%lf",&v0,&tf);
  double v = findFinalVelocity(v0, tf);
  printf("Final velocity = %lf\n", v);
  
  //change 2
  // change1
  
}

