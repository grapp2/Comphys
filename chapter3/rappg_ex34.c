/*
Greg Rapp
EX 3.4
9/9
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double getp(int i, double x);
double geterror(double p,double pstar);
double factorial(int i);
const double pi=3.141592653589793;
int main(int argc, char *argv[])
{
  int i,N,ni;
  int M=50; //set the maximum number of allowable steps
  double tolerance=0.0;
  double error=0.0;
  double p=0.0;
  double pstar;
  double x;
  FILE *out,*rsp;
  x=pi/4.0;
    while (tolerance <= 0.0) {
      if (argc != 2) {
        printf("\nEnter the tolerance (scientific notation, e.g. 1.5e-13) > ");
        ni = scanf("%le",&tolerance);
      } else tolerance=atof(argv[1]);
      if (tolerance == 0.0) {
        printf("\nTolerance can not be zero or negative, try again...\n\n");
        return(0);
      }
    }
    pstar=sin(x);
    out = fopen("output34.dat","w");
    for (i=1;i<=M;i++) {
      p=p+getp(i,x);
      error=geterror(p,pstar);
      fprintf(out,"%d %le\n",i,error);
      if (error<tolerance) {
        break;
      }
      if (i==M) {
        printf("\nThe number of iterations exceeds allowable maximum, retry\n");
        printf("\nwith new tolerance or change max limit.\n");
        break;
      }
    }
    fclose(out);
    if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
      printf("\nCannot open gnuplot.rsp for writing\n");
      exit(1);
    }
    fprintf(rsp,"plot ’%s’ using 1:2 with lines\n","output34.dat");
    fprintf(rsp,"pause mouse\n");
    fprintf(rsp,"replot\n");
    fclose(rsp);
    if(system("gnuplot gnuplot.rsp") == -1) {
      printf("\nCommand could not be executed\n");
      exit(1);
    }
return(0);
}
double getp(int i, double x)
{
  int term0;
  double term1,term2;
  term0=2*(i-1)+1;
  term1=pow( (-1.0),(i+1) );
  term2=( pow(x,term0) / factorial(term0) );
  return( term1*term2 );
}
double geterror(double p, double pstar)
{
  return ( fabs(pstar-p) );
}
double factorial(int i)
{
  int j;
  double result=1.0;
  if (i==0) {
    return(1.0);
  }
  else {
    for (j=1;j<=i;j++) {
      result=result*(double)j;
    }
  }
  return(result);
}
