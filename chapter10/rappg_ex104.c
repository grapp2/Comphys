/*
  Greg Rapp
  11/24/2020
  Chapter 10 Exercise 4
*/
#include <stdio.h>
#include <math.h>
#include "comphys.c"
#include "comphys.h"
void plotData(char *a);
int main(){
  FILE *out;
  char a[80] = "104.txt";;
  float rc, vin;
  float *dat, *respns, *ans;
  int i;
  int n = 128;
  int m = 128;
  float dt = 0.1;
  float t = 6.4;
  int index = 1;
  float *tdat;
  rc = 1;
  ans = vector(1,n*2);
  dat = vector(1,n);
  respns = vector(1,m);
  tdat = vector(1,n);
  while (t >= -6.4){
    if (t >= 0 && t < 1){
      dat[index] = 1;
      respns[index] = exp(-t/rc);
    }
    else{
      dat[index] = 0;
      respns[index] = 0;
    }
    index++;
    t -= 0.1;
  }
  t = -6.4;
  index = 1;
  while(t <= 6.4){
    tdat[index] = t;
    t += .1;
    index++;
  }
  convlv(dat,n,respns,m,1,ans);
  out = fopen(a,"w");
  for (i = 1; i <= n/2; i++){
    fprintf(out,"%f %f\n",tdat[i],ans[i]);
  }
  for (i = n; i >= n/2+1; i--){
    fprintf(out,"%f %f\n",tdat[i],ans[i]);
  }
  fclose(out);

  plotData(a);
}
void plotData(char *a){
  FILE *rsp;
  if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }
  fprintf(rsp,"set xrange[-6.4:6.4]\n",a);
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


