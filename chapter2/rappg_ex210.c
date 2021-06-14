/*
Greg Rapp
EX 2.10
9/9
*/
#include <stdio.h>
#include <stdlib.h>
#include "comphys.h"
#include "comphys.c"
double findSD(float a[],double avg, int n);
int main(){
  FILE *in;
  float grain[50];
  int i;
  double avg;
  double total = 0;
  double sd;
  int bin1 = 0;
  int bin2 = 0;
  int bin3 = 0;
  int bin4 = 0;
  int bin5 = 0;
  int bin6 = 0;
  int bin7 = 0;
  int bin8 = 0;
  int bin9 = 0;
  int bin10 = 0;
  in = fopen("grains.dat","r");
  for(i=0;i<50;i++){
    fscanf(in,"%f",&grain[i]);
    total = total + grain[i];
  }
  fclose(in);
  avg = total/50;
  qsfloat(grain, 0, 49);
  for(i=0;i<50;i++){
    printf("grain[%d] = %f\n",i,grain[i]);
    if (grain[i] < 1.1 && grain[i] >= 1.0){
      bin1++;
    }
    else if (grain[i] <= 1.2 && grain[i] > 1.1){
      bin2++;
    }
    else if (grain[i] <= 1.3 && grain[i] > 1.2){
      bin3++;
    }
    else if (grain[i] <= 1.4 && grain[i] > 1.3){
      bin4++;
    }
    else if (grain[i] <= 1.5 && grain[i] > 1.4){
      bin5++;
    }
    else if (grain[i] <= 1.6 && grain[i] > 1.5){
      bin6++;
    }
    else if (grain[i] <= 1.7 && grain[i] > 1.6){
      bin7++;
    }
    else if (grain[i] <= 1.8 && grain[i] > 1.7){
      bin8++;
    }
    else if (grain[i] <= 1.9 && grain[i] > 1.8){
      bin9++;
    }
    else if (grain[i] <= 2.0 && grain[i] > 1.9){
      bin10++;
    }
  }
  printf("1.0-1.1: %d\n1.1-1.2: %d\n1.2-1.3: %d\n1.3-1.4: %d\n1.4-1.5: %d\n1.5-1.6: %d\n1.6-1.7: %d\n1.7-1.8: %d\n1.8-1.9: %d\n1.9-2.0: %d\n",bin1,bin2,bin3,bin4,bin5,bin6,bin7,bin8,bin9,bin10);
  printf("Average = %lf\n",avg);
  sd = findSD(grain,avg,50);
  printf("Standard Deviation = %lf\n",sd);
  return 0;
}

double findSD(float a[], double avg, int n){
  double sd = 0;
  for (int i=0;i<n;i++){
    sd += pow(a[i]-avg,2);
  }
  sd = sd * (1/(double) n);
  sd = sqrt(sd);
  return sd; 
}
