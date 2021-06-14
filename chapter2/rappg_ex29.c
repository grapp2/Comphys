/*
Greg Rapp
EX 2.9
9/9
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"

int main()
{
  long idum = -1;
  time_t now;
  float x,rn;
  int bin1,bin2,bin3,bin4;
  /* Use the time function to supply a different seed to the
  random number generator every time the program is run */

  now = time(NULL);
  idum = -1*now;

  /* Initialize random number generator */

  rn = ran1(&idum);

  /* Now you can generate any number of random numbers between 0.0
  and 1.0 with statements like the following: */
  bin1=0;
  bin2=0;
  bin3=0;
  bin4=0;
  for (int i = 0; i < 1000; i++){
    x = ran1(&idum);
    if (x <0.25 && x >= 0){
      bin1++;
    }
    else if ((x >= 0.25) && (x < 0.5)){
      bin2++;
    }
    else if ((x >= 0.5) && (x < 0.75)){
      bin3++;
    }
    else if ((x >= .75) && (x < 1)){
      bin4++;
    }
  }
  printf("0-0.25: %d\t0.25-0.5: %d\t0.5-0.75: %d\t0.75-1.0: %d\n",bin1,bin2,bin3,bin4);
}
