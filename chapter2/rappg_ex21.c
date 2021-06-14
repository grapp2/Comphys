#include <stdio.h>

double findVelocity(double v0,int t)
{
  return v0+(-9.8*t);
}

int main()
{
  double v0;
  double v;
  int t = 0;
  printf("Enter initial velocity: ");
  scanf("%lf", &v0);
  while (t <= 100)
  {
    if (t % 5 == 0)
    {
      v = findVelocity(v0,t);
      printf("t = %d v = %4.2lf\n", t, v);
    }
    t = t+1;
  }
}

