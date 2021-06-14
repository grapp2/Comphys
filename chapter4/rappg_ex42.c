/*
Greg Rapp
9/23/2020
ex4-2
*/
#include <stdio.h>

double linearInterp(double xn[],double yn[],double x);

double xin[] = {3511,3638,4047,4358,4416,4579,4658,4727,4765,4800,4861,4880,4965,5017,5145,5320,5461,5876,5893,6328,6438,6563,6943,7860,8210,8300,8521,9040,10140,10600,13000,15000,15500,19701,23254};
double yin[] = {1.53894,1.53648,1.53024,1.52669,1.52611,1.52462,1.52395,1.52339,1.52310,1.52283,1.52238,1.52224,1.52165,1.52130,1.52049,1.51947,1.51872,1.5168,1.51673,1.51509,1.51472,1.51432,1.51322,1.51106,1.51037,1.51021,1.50981,1.50894,1.50731,1.50669,1.50371,1.5013,1.50068,1.495,1.48929};

int main(){
  double wavelength;
  double index;
  printf("Enter wavelength in angstroms: ");
  scanf("%lf",&wavelength);
  index = linearInterp(xin,yin,wavelength);
  printf("Calculated index of refraction: %lf\n", index);
  return 0;
}

double linearInterp(double xn[],double yn[],double x){
  double b;
  double m;
  double y;
  int j;
  for(int i=0;i<35;i++) {
    if(xn[i] < x && xn[i+1] >= x) {
      j = i;
      break;
    }
  }
  m = (yn[j]-yn[j+1])/(xn[j]-xn[j+1]);
  b = yn[j]-m*xn[j];
  y = m*x+b;
  return y;
}

