/*
  Greg Rapp
  9/30/2020
  ex 6.3
  Not sure how to prompt the user after the program shows a gnuplot but pressing ctrl + c
  after the function is plotted is a work around I found. Feedback would be appreciated.
*/
#include <stdio.h>
#include <stdlib.h>
#include "comphys.h"
#include "comphys.c"
float bracketBess(float a, float b, float c);

int main(){
  FILE *out, *rsp;
  char outfile[80] = "out63.dat";
  float y,a,b,c,res;
  float x = 0;
  out = fopen(outfile,"w");

  while (x <= 15){
    y = bessj0(x);
    fprintf(out,"%lf %lf\n",x,y);
    x += 0.1;
  }
  fclose(out);
  if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }
  fprintf(rsp,"plot '%s' using 1:2 with lines\n",outfile);
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fclose(rsp);
  if(system("gnuplot gnuplot.rsp") == -1) {
    printf("\nCommand could not be executed\n");
    exit(1);
  }
  printf("Enter bracket triplet (A,B,C): ");
  scanf("%f,%f,%f",&a,&b,&c);
  res = bracketBess(a,b,c);
  if ((res > c -0.0001 && res < c + 0.0001) || (res > a -0.0001 && res < a + 0.0001)){
    printf("Could not find minimum within bracket\n");
  }
  else{
    printf("Minimum within bracket: %f\n",res);
  }
  return(0);
}

float bracketBess(float a, float b, float c){
  float A,C,x,ya,yb,yc,yx;
  float eps = 1e-5;
  A=a;
  C=c;
  while(fabs(a-c) > eps*fabs(A-C)){
    ya = bessj0(a);
    yb = bessj0(b);
    yc = bessj0(c);
    if(fabs(b-a) > fabs(b-c)){
      x = ((a+b)/(double) 2);
      yx = bessj0(x);
      if (yx > yb){
        a = x;
      }
      else if (yx <= yb){
        c = b;
        b = x;
      }
    }
    else if (fabs(b-c) >= fabs(b-a)){
      x = ((b+c)/(double) 2);
      yx = bessj0(x);
      if (yx > yb){
        c = x;
      }
      else if (yx <= yb){
        a = b;
        b = x;
      }
    }
  }
  return x;
}
