/*
  Greg Rapp
  11/24/2020
  Chapter 10 exercise 3
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comphys.h"
#include "comphys.c"
int size = 512;
float time = 12; // last data point of x data in the file
void plotData(char *a,char *b, char *c);

int main(){
  FILE *in,*transform1,*lpf,*transform2;
  float *datx, *daty, *freq;
  char *a = "trans1.dat";
  char *b = "lpf.dat";
  char *c = "trans2.dat";
  int i = 1;
  datx = vector(1,size);
  daty = vector(1,size);
  freq = vector(1,size);

  in = fopen("signal.dat","r");
  while (fscanf(in,"%f %f",&datx[i],&daty[i]) != EOF){
    printf("%f %f\n",datx[i],daty[i]);
    i++;
  }
  for (i = 1; i <= size; i++){
    freq[i] = i/time;
  }
  // zero pad if size != 2^n, not in this case since we have 512 points
  // call realft
  realft(daty,size,1);
  // graph data
  transform1 = fopen(a, "w");
  for (i = 1; i <= size; i++){
    fprintf(transform1,"%f %f\n", freq[i], daty[i]);
  }
  fclose(transform1);

  // apply low pass filter
  for (i = 1; i <= size; i++){
    if (freq[i] > 5){
      daty[i] = 0;
    }
  }
  // graph data
  lpf = fopen(b, "w");
  for (i = 1; i <= size; i++){
    fprintf(lpf,"%f %f\n", freq[i], daty[i]);
  }
  fclose(lpf);
  // call realft again
  realft(daty,size,-1);
  // graph data
  transform2 = fopen(c, "w");
  for (i = 1; i <= size; i++){
    fprintf(transform2,"%f %f\n", freq[i], daty[i]);
  }
  fclose(transform2);
  plotData(a,b,c);
  return 0;
}

void plotData(char *a,char *b,char *c){
  FILE *rsp;
  if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }
  fprintf(rsp,"plot '%s' using 1:2 with lines\n",a);
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fprintf(rsp,"plot '%s' using 1:2 with lines\n",b);
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fprintf(rsp,"plot '%s' using 1:2 with lines\n",c);
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fclose(rsp);
  if(system("gnuplot gnuplot.rsp") == -1) {
    printf("\nCommand could not be executed\n");
    exit(1);
  }
  return;
}
