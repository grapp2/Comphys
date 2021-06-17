#include <stdio.h>
#include <math.h>
const double L = 3.839E+26;
const double pi = 3.141592653589793;

double findSolar(double l, double r)
{
  r = r * 1.496E+11;
  return (l/(4*pi*pow(r,2)));
}
int main()
{
  double r;
  printf("Enter distance between sun and planet in AU: ");
  scanf("%lf", &r);
  double a = findSolar(L, r);
  printf("Computed solar constant: %e\n",a);
  return 0;
  //another change
}
