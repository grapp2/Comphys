/*
Greg Rapp
EX 2.5
9/9
*/
#include <stdio.h>
#include <math.h>
const double pi = 3.14159265359;
int main()
{
  double bigE0,bigE1,E,e,newE,M,m;
  printf("Enter e: ");
  scanf("%lf", &e);
  printf("Enter M (degrees): ");
  scanf("%lf", &m);
  newE = m;
  M = m*(pi/180);
  for (int i = 0; i < 5; i++)
  {
    E = newE;
    bigE0 = M+e*sin(E);
    bigE1 =  M+e*sin(bigE0);
    newE = (bigE1+bigE0)/2;
    printf("E = %lf\n", newE*(180/pi));
  }
  return 0;
}
