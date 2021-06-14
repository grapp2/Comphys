/*
  Greg Rapp
  10/26/2020
  exercise 7.14
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comphys.h"
#include "comphys.c"
int main()
{
  FILE *out,*rsp;
  int N = 50;
  int a;
  float e,e0,e1,R,r,T,rn;
  float J = 2.0;
  float k = 0.001;
  int particles[N];
  long idum = -1;
  time_t now;
  /* Use the time function to supply a different seed to the
  random number generator every time the program is run */
  now = time(NULL);
  idum = -1*now;
  /* Initialize random number generator */
  rn = ran1(&idum);

  printf("Enter Temperature: ");
  scanf("%f",&T);
  if (T < 0){
    printf("Invalid Temperature\nEnter Temperature: ");
    scanf("%f",&T);
  }
  // step 1: generate random spins.
  for (int i = 0; i < N; i++){
    rn = ran1(&idum);
    if(rn < 0.5) particles[i] = -1;
    else particles[i] = 1;
  }
  out = fopen("energies.dat","w");
  // steps 2-3
  for (int i = 0; i < 5000; i++){
    e0 = 0;
    for(int j = 0; j < N-1; j++) e0 += particles[j] * particles[j+1];
    e0 *= -J;
    a = (int) N*ran1(&idum);
    particles[a] *= -1;
    e1 = 0;
    for(int j = 0; j < N-1; j++) e1 += particles[j] * particles[j+1];
    e1 *= -J;
    if(e1 > e0){
      R = exp(-(e1-e0)/(k*T));
      r = ran1(&idum);
      if (R <= r){
        particles[a] *= -1;
        e = e0;
      }
      else if (R > r){
        e = e1;
      }
    }
    else e = e1;
    fprintf(out,"%d %f\n",i,e);
  }
  fclose(out);
  if((rsp = fopen("gnuplot.rsp","w")) == NULL) {
    printf("\nCannot open gnuplot.rsp for writing\n");
    exit(1);
  }
  fprintf(rsp,"plot 'energies.dat' using 1:2 with lines\n");
  fprintf(rsp,"pause mouse\n");
  fprintf(rsp,"replot\n");
  fclose(rsp);
  if(system("gnuplot gnuplot.rsp") == -1) {
    printf("\nCommand could not be executed\n");
    exit(1);
  }
  return(0);
}
