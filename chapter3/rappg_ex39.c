/*
Greg Rapp
EX 3.9
9/9
*/
#include <stdio.h> 
#include <stdlib.h>
#include "comphys.c"
#include "comphys.h"

double findRelTemp(double co2);
FILE *in; 
int main() { 
  double result,max,min,avgE,avgL;
  double *co2s;
  int *dates;
  int count1,count2,count3 = 0;
  max = 0;
  min = 1e10;
  avgE = 0;
  avgL = 0;
  dates = ivector(0,283);
  co2s = dvector(0,283);
  in = fopen("vostok_co2.dat","r");
  while(fscanf(in,"%d %lf", &dates[count1], &co2s[count1]) != EOF) {
    count1++;
  }
  for (int i=0;i < count1;i++){
    if(max < co2s[i]){
       max = co2s[i];
    }
    else if(min > co2s[i]){
       min = co2s[i];
    }
    else if(dates[i] >= 112000 && dates[i]<= 130000){
      avgE += co2s[i];
      count2++;
    }
    else if(dates[i] >= 138000 && dates[i]<= 175000){
      avgL += co2s[i];
      count3++;
    }
  }
  avgE /= (double) count2;
  avgL /= (double) count3;
  printf("max = %lf\tmin = %lf\taverage in eemian = %lf\taverage in Illinoian = %lf\n",max,min,avgE,avgL);
  fclose(in);
}
