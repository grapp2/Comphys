/*
  Greg Rapp
  10/26/2020
  exercise 7.12
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
  float x,y,rn,f,integral,V,sum,av,sum2,av2,m,me,X,Xe,Y,Ye;
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

  // calculate M
  V = 2.0;
  sum = 0.0;
  sum2 = 0.0;
  for(i=0;i<N;i++) {
    //find random number from 0 to 1 for x and 0 to 2 for y
    x = ran1(&idum);
    y = 2.0*ran1(&idum);
    if(y <= -2*x+2) f = y*sin(x*x)+2;
    else f = 0.0;
    sum += f;
    sum2 += f*f;
  }
  /* Calculate integral and store integral in m and error in me */
  av = sum/(float)N;
  av2 = sum2/(float)N;
  integral = av*V;
  error = V*sqrt((av2-av*av)/(float)N);
  m = integral;
  me = error/m;

  // Calculate X
  sum = 0.0;
  sum2 = 0.0;
  for(i=0;i<N;i++) {
    //find random number from 0 to 1 for x and 0 to 2 for y
    x = ran1(&idum);
    y = 2.0*ran1(&idum);
    if(y <= -2*x+2) f = x*(y*sin(x*x)+2);
    else f = 0.0;
    /* Evaluate sums */
    sum += f;
    sum2 += f*f;
  }
  av = sum/(float)N;
  av2 = sum2/(float)N;
  integral = (1/m)*(av*V);
  error = V*sqrt((av2-av*av)/(float)N);
  X = integral;
  Xe = error/m;

  // Calculate Y
  sum = 0.0;
  sum2 = 0.0;
  for(i=0;i<N;i++) {
    // find random number from 0 to 1 for x and 0 to 2 for y
    x = ran1(&idum);
    y = 2.0*ran1(&idum);
    if(y <= -2*x+2) f = y*(y*sin(x*x)+2);
    else f = 0.0;
    /* Evaluate sums */
    sum += f;
    sum2 += f*f;
  }
  av = sum/(float)N;
  av2 = sum2/(float)N;
  integral = (1/m)*(av*V);
  error = V*sqrt((av2-av*av)/(float)N);
  Y = integral;
  Ye = error;
  
  printf("\nM = %f +/- %f, X = %f +/- %f, Y = %f +/- %f\n",m,me,X,Xe,Y,Ye);
  return(0);
}
