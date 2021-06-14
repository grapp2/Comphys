/*
Greg Rapp
EX 3.7
9/9
*/
#include <stdio.h> 
#include <stdlib.h>
double findRelTemp(double co2);
FILE *in, *out; 
int main() { 
  double result;
  double co2;
  int date;
  in = fopen("vostok_co2.dat","r");
  out = fopen("convertedco2data.dat","w");
  while(fscanf(in,"%d %lf", &date, &co2) != EOF) {
    result = findRelTemp(co2);
    fprintf(out,"%d\t%lf\n",date,result);
  }
  fclose(in);
  fclose(out);
}
double findRelTemp(double co2){
  return (2.5*(co2-365.0)/280.0);
}
