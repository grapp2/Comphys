/*
Greg Rapp
EX 2.11
9/9
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.c"
#include "comphys.h"
float findS1(float sigma);
float findS2(float sigma);
float findS3(float sigma);

int main(){
  float rn,x;
  long idum;
  float s0, s1;
  rn = ran1(&idum);
  time_t t;
  t = time(NULL);
  idum = -1*t;
  for (int i = 0; i<100; i++){
    /* Not sure why e is not between 0 and 10 */
    x = 10*ran1(&idum);
    if (x < 4.5553){
      s0 = findS1(x);
      printf("e = %f\tS = %f\n",x,s0);
    }
    else if (x > 4.5553){
      s0 = findS2(x);
      s1 = findS3(x);
      /*not sure how to make % print*/
      printf("e = %f\t35.4 S = %f\t64.6 S = %f\n",s0,s1);
    }
  }
  return 0;
}

float findS1(float sigma){
  return (7.3329 +1.1107*sigma);
}

float findS2(float sigma){
  return (12.3925 + (sigma-4.5553)+0.23*pow((sigma-4.5553),2));
}

float findS3(float sigma){
  return (12.3925 + 4.9311*(sigma-4.5553) - 1.02*pow((sigma-4.5553),2));
}
