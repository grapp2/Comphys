/*
Greg Rapp
9/23/2020
ex4-10
*/
#include <stdio.h>
#include <stdlib.h>
double T[4] = {23,24,25,26};
double L[3] = {1,3,5};
void interp(double waves[], double int1[],double int2[],double int3[],double int4[], int a, int b, double t, double l);

int main(){
  FILE *in1,*in2,*in3,*in4;
  int count,j,k;
  char *SD[3][4] = {{"t230l10p00.rbn","t240l10p00.rbn","t250l10p00.rbn","t260l10p00.rbn"},
    {"t230l30p00.rbn","t240l30p00.rbn","t250l30p00.rbn","t260l30p00.rbn"},
    {"t230l50p00.rbn","t240l50p00.rbn","t250l50p00.rbn","t260l50p00.rbn"}};
  double t,l,y,wave,wavelengths[1640],intensity1[1640],intensity2[1640],intensity3[1640],intensity4[1640];

  printf("Enter temperature and luminosity separated by a comma: ");
  scanf("%lf,%lf",&t,&l);
  /*
  find bracket
  */
  for (int i = 0; i < 4; i++){
    if (T[i] < t && T[i+1] >= t){
      j = i;
      break;
    }
  }
  for(int i = 0; i< 3; i++){
    if (L[i] < l && L[i+1] >= l){
      k = i;
      break;
    }
  }
  /*
  read data into vectors intensity1-4
  */
  in1 = fopen(SD[j][k],"r");
  in2 = fopen(SD[j][k+1],"r");
  in3 = fopen(SD[j+1][k+1],"r");
  in4 = fopen(SD[j+1][k],"r");
  count = 0;
  while(fscanf(in1,"%lf",&wave) != EOF) {
    wavelengths[count] = wave;
    fscanf(in1,"%lf",&intensity1[count]);
    count++;
  }
  count = 0;
  while(fscanf(in2,"%lf",&wave) != EOF) {
    fscanf(in2,"%lf",&intensity2[count]);
    count++;
  }
  count = 0;
  while(fscanf(in3,"%lf",&wave) != EOF) {
    fscanf(in3,"%lf",&intensity3[count]);
    count++;
  }
  count = 0;
  while(fscanf(in4,"%lf",&wave) != EOF) {
    fscanf(in4,"%lf",&intensity4[count]);
    count++;
  }
  interp(wavelengths,intensity1,intensity2,intensity3,intensity4,j,k,t,l);
  fclose(in1);
  fclose(in2);
  fclose(in3);
  fclose(in4);
}
void interp(double waves[], double int1[],double int2[],double int3[],double int4[], int a, int b,double x1, double x2){
  FILE *out;
  double y1,y2,y3,y4,t,u,y;
  /*
  t and u are constants, calculate them outside for loop
  */
  t = (x1 - T[a])/(T[a+1]-T[a]);
  u = (x2 - L[b])/(L[b+1]-L[b]);
  out = fopen("InterpolatedData.dat","w");
  for (int i = 0; i < 1640; i++){
    y1 = int1[i];
    y2 = int2[i];
    y3 = int3[i];
    y4 = int4[i];
    y = (1-t)*(1-u)*y1+t*(1-u)*y2+t*u*y3+(1-t)*u*y4;
    fprintf(out,"%lf\t%lf\n",waves[i],y);
  }
  fclose(out);
}
