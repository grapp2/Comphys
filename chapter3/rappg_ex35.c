/*
Greg Rapp
EX 3.5
9/9
*/
#include <stdio.h>
#include <stdlib.h> /* Needed for exit() */
#include <math.h>
double planck(double wave, double T);
int main()
{
  double wave,T;
  double result;
  int ni;
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
  while(fscanf(in,"%lf",&wave) != EOF) {
    result = planck(wave,T);
    fprintf(out,"%7.1f %e\n",wave,result);
  }
  fclose(out);
  fclose(in);
  
  /*rsp = fopen("gnuplot.rsp","w");
  if(rsp == NULL) {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }
  fprintf(rsp,"plot ’%s’ using 1:2 with lines\n", outfile);
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fclose(rsp);
  if(system("gnuplot gnuplot.rsp") == -1) {
    printf("\nCommand could not be executed\n");
    exit(1);
  }*/

return(0);
}
double planck(double wave, double T)
{
  static double p = 1.19106e+27;
  double p1;
  p1 = p/(pow(wave,5.0)*(exp(1.43879e+08/(wave*T)) - 1.0));
  return(p1);
}
