/*
  Greg Rapp
  10/26/2020
  exercise 7.13
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
  float px,py,x,y,rn,f,integral,V,sum,av,sum2,av2;
  float error;
  printf("Enter x and y separated by a comma: ");
  scanf("%f,%f",&px,&py);
  if((px > -2 && px < 2 ) || (py > -2 && py < 2 )){
    printf("\nInvalid Position\nEnter starting position: ");
    scanf("%lf,%lf",&px,&py);
  }
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
  V = 4.0;
  sum = 0.0;
  sum2 = 0.0;
  for(i=0;i<N;i++) {
    x = 2.0*ran1(&idum)-1.0;
    y = 2.0*ran1(&idum)-1.0;
    f = (x*x+y*y)/sqrt(pow((x-px),2)+pow((y-py),2));
    /* Evaluate sums */
    sum += f;
    sum2 += f*f;
  }
  /* Calculate Integral and error */
  av = sum/(float)N;
  av2 = sum2/(float)N;
  integral = av*V;
  error = V*sqrt((av2-av*av)/(float)N);
  printf("\nCalculated gavitational potential = %f +/- %f\n",integral,error);
  return(0);
}
