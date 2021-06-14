/*
  Greg Rapp
  9/30/2020
  exercise 5.11
*/
#include <stdio.h>
#include <math.h>
double addedEquations(double tS);
double solve4TS(double bigtA, double tS);

const double aS = 0.11;
const double tA = 0.53;
const double aA = 0.3;
const double tAprime = 0.06;
const double aAprime = 0.31;
const double c = 2.5;
const double S = 1365;
const double sig = 5.67e-8;

int main(){
  double bigtA,tS0;
  double tS1 = 273;
  while (fabs(tS1-tS0) > 1e-4){
    tS0 = tS1;
    bigtA = addedEquations(tS0);
    tS1 = solve4TS(bigtA,tS0);
    tS1 = (tS1+tS0)/(double) 2;
  }
  printf("calculated tS: %lf\n", tS1);
}

double addedEquations(double tS){
  return pow((S/((double) 4*sig)*(-1+aA))+(pow(tS,4)*tAprime),0.25);
}

double solve4TS(double bigtA, double tS){
  return pow((tA/sig*(1.0-aS)/(1.0-aAprime)*S/(double) 4) - (c/(sig*(1.0-aAprime))*(tS-bigtA)+1.0/(1.0-aAprime)*pow(tA,4)),0.25);
}
