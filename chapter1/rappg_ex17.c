#include <stdio.h>
#include <math.h>
const double L = 3.839E+26;
const double pi = 3.141592653589793;
const double sigma = 5.671E-8;
double calcT(double a, double r, double l) {
  double p = (l*(1-a))/(16*pi*sigma*pow(r,2));
  return pow(p,0.25);
}

int main() {
  double r;
  double a;
  printf("Enter value for R and a separated by a comma: ");
  scanf("%lf,%lf",&r, &a);
  double t = calcT(a,r,L);
  printf("Surface blackbody temperature = %lf\n",t);
}

