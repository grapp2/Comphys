/*
  Greg Rapp
  10/26/2020
  exercise 7.11
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
double pi = 3.1415926;
int main()
{
  int N;
  float x,y,rn,r2,f,integral,V,sum,av,sum2,av2;
  float error;
  long i;
  long idum = -1;
  time_t now;
  printf("Enter number of points: ");
  scanf("%d",&N);
  /* Use the time function to supply a different seed to the
  random number generator every time the program is run */
  now = time(NULL);
  idum = -1*now;
  /* Initialize random number generator */
  rn = ran1(&idum);

  sum = 0.0;
  sum2 = 0.0;
  for(i=0;i<N;i++) {
    x = 2.0*ran1(&idum)-1;
    y = pi*ran1(&idum)-(pi/2.0);
    f = x*x*cos(y);
    /* Evaluate sums */
    sum += f;
    sum2 += f*f;
  }
  /* Calculate Integral and error */
  av = sum/(float)N;
  av2 = sum2/(float)N;
  integral = av*(2*pi);
  error = (2*pi)*sqrt((av2-av*av)/(float)N);
  printf("\nIntegral = %f +/- %f\n",integral,error);
  return(0);
}
