/*
  Greg Rapp
  11/24/2020
  Chapter 10 exercise 6
*/
#include <stdio.h>
#include "comphys.c"
#include "comphys.h"
void plotData(char *a);

int main(){
  FILE *in0, *in1, *out;
  char a[80], b[80], outfile[80];
  float *lag,*daty0,*daty1,*ans;
  int n = 1024;
  int i;
  printf("Enter first dataset file name: ");
  scanf("%s", &a);
  printf("Enter second dataset file name: ");
  scanf("%s", &b);

  lag = vector(1,n);
  daty0 = vector(1,n);
  daty1 = vector(1,n);
  ans = vector(1,n*2);

  i = 1;
  in0 = fopen(a,"r");
  while (fscanf(in0,"%f %f",&lag[i],&daty0[i]) != EOF){
    i++;
  }
  fclose(in0);

  i = 1;
  in1 = fopen(b, "r");
  while (fscanf(in1,"%f %f",&lag[i],&daty1[i]) != EOF){
    i++;
  }
  fclose(in0);

  correl(daty0,daty1,n,ans);

  out = fopen(outfile,"w");
  for (i = 1; i <= n/2; i++){
    fprintf(out,"%f %f\n",lag[i], ans[i]);
  }
  for (i = n; i >= n/2+1; i--){
    fprintf(out,"%f %f\n",lag[i], ans[i]);
  }
  fclose(out);

  plotData(outfile);
}


void plotData(char *a){
  FILE *rsp;
  if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }
  fprintf(rsp,"plot '%s' using 1:2 with lines\n",a);
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fclose(rsp);
  if(system("gnuplot gnuplot.rsp") == -1) {
    printf("\nCommand could not be executed\n");
    exit(1);
  }
  return;
}
