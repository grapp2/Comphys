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

}
