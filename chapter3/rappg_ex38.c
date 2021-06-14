/*
Greg Rapp
EX 3.8
9/9
*/

#include <stdio.h>
#include <stdlib.h> /* Needed for exit() */
#include <math.h>
#include "comphys.c"
#include "comphys.h"
double plank(double wave, double T);
int main()
{
  double wave,T,result;
  double *waves;
  int count;
  char outfile[80];
  FILE *in;
  FILE *out, *rsp;
  printf("\nEnter the temperature in Kelvin > ");
  scanf("%lf",&T);
  printf("\nEnter the name of the output file > ");
  scanf("%s",outfile);
  out = fopen(outfile,"w");
  if(out == NULL) {
    printf("\nCannot open %s for writing\n",outfile);
    exit(1);
  }
  in = fopen("inputwave.dat","r");
  waves = dvector(0,23);
  count = 0;
  while(fscanf(in,"%lf",&waves[count]) != EOF) {
    result = plank(waves[count],T);
    printf("result = %lf\n",result);
    fprintf(out,"%7.1f %e\n",waves[count],result);
    count++;
  }
  fclose(out);
  fclose(in);
  return(0);
}
double plank(double wave, double T){
    static double p = 1.19106e+27;
    double p1;
    p1 = p/(pow(wave,5.0)*(exp(1.43879e+08/(wave*T)) - 1.0));
    return(p1);
}

