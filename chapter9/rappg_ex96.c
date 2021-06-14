/*
  Greg Rapp
  11/11/2020
  exercise 9.6
  does not compute correct values, prints out initial guess to
  the output file with unrealistic error.
*/
#include <stdio.h>
#include <math.h>
#include "comphys.c"
#include "comphys.h"
#define NDATA 51
#define MA 4
void fgauss(float x, float a[], float *y, float dyda[], int na);
int main()
{
  float *x,*y,*sig,**covar,**alpha,*a,chisq,ochisq,alambda;
  int *ia,ma;
  char outname[80];
  FILE *in,*init,*out;
  int i,k,ndata;
  x = vector(1,NDATA);
  y = vector(1,NDATA);
  sig = vector(1,NDATA);
  a = vector(1,MA);
  covar = matrix(1,MA,1,MA);
  alpha = matrix(1,MA,1,MA);
  ia = ivector(1,MA);

  ma = MA;
  if((in = fopen("decay.out","r")) == NULL)
  nrerror("Cannot find input file");
  printf("Enter output file > ");
  scanf("%s",&outname);
  out = fopen(outname,"w");

  k = 1;
  while(fscanf(in,"%f %f",&x[k],&y[k]) != EOF) {
    sig[k] = 1;
    k++;
  }
  ndata = k-1;

  //initialize data
  a[1] = 10.1;
  a[2] = 3;
  a[3] = .5;
  a[4] = .2;
  /* We are fitting all parameters a[1] .. a[4], so we fill up all
  entries in ia[] with 1’s */
  for(i=1;i<=MA;i++){
     ia[i] = 1;
  }
  /* Initializing mrqmin using a negative value of alambda.
  Note we are passing the function fgauss to mrqmin. See
  below. */
  alambda = -1.0;
  chisq = 0.0;
  mrqmin(x,y,sig,ndata,a,ia,ma,covar,alpha,&chisq,fgauss,&alambda);
  ochisq = chisq + 2.0;

  /* Iterating with mrqmin until relative change in chisq is less
  than 0.001 */
  while(fabs((ochisq - chisq)/ochisq) > 0.001 ) {
    ochisq = chisq;
    mrqmin(x,y,sig,ndata,a,ia,ma,covar,alpha,&chisq,fgauss,&alambda);
  }
  /* Here we run mrqmin one more time with alambda = 0.0 to get
  covariant matrix, in case we want the errors */
  alambda = 0.0;
  mrqmin(x,y,sig,ndata,a,ia,ma,covar,alpha,&chisq,fgauss,&alambda);
  /* Print out the results (the a’s) along with the errors (the
  squareroots of the diagonal members of the covariant matirx
  divided by the number of degrees of freedom). */
  for(i=1;i<=MA;i++) fprintf(out,"%f %f\n",a[i],sqrt(chisq*covar[i][i]/(float)(ndata-MA)));
  return(0);
}
/* For a given value of x, and input parameters a[], this function
returns the resulting value of y and the vector dyda[] which
contains the derivatives of y with respect to all of the a[]
parameters */
void fgauss(float x, float a[], float *y, float dyda[], int na)
{
  int i;
  // load y with the expression and dyda with the partial derivatives
  *y = a[1]*exp(-a[2]*x)*sin(a[3]*x+a[4]);
  dyda[1]=exp(-a[2]*x)*sin(a[3]*x +a[4]);
  dyda[2]=-a[1]*x*sin(a[3]*x+a[4])*exp(-x*a[2]);
  dyda[3]=a[1]*x*exp(-a[2]*x)*cos(x*a[3]+a[4]);
  dyda[4] = a[1]*exp(-a[2]*x)*cos(a[4] + a[3]*x);
  return;
}
