/*
Greg Rapp
9/23/2020
ex4-5
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
  double x1,x2,x3,x4,y1,y2,y3,y4,y,term1,term2,term3,term4;
  int size = 35;
  int j;
  for(int i=0;i<size;i++) {
    if(xn[i] < x && xn[i+1] >= x) {
      j = i;
      break;
    }
  }
  if (j == 0){
    x1 = xn[j];
    x2 = xn[j+1];
    x3 = xn[j+2];
    x4 = xn[j+3];
    y1 = yn[j];
    y2 = yn[j+1];
    y3 = yn[j+2];
    y4 = yn[j+3];
  }
  else if (j == size-2){
    x1 = xn[j-2];
    x2 = xn[j-1];
    x3 = xn[j];
    x4 = xn[j+1];
    y1 = yn[j-2];
    y2 = yn[j-1];
    y3 = yn[j];
    y4 = yn[j+1];
  }
  else if (j == size-1){
    x1 = xn[j-3];
    x2 = xn[j-2];
    x3 = xn[j-1];
    x4 = xn[j];
    y1 = yn[j-3];
    y2 = yn[j-2];
    y3 = yn[j-1];
    y4 = yn[j];
  }
  else{
    x1 = xn[j-1];
    x2 = xn[j];
    x3 = xn[j+1];
    x4 = xn[j+2];
    y1 = yn[j-1];
    y2 = yn[j];
    y3 = yn[j+1];
    y4 = yn[j+2];
  }
  term1 = ((x-x2)*(x-x3)*(x-x4))/((x1-x2)*(x1-x3)*(x1-x4))*y1;
  term2 = ((x-x1)*(x-x3)*(x-x4))/((x2-x1)*(x2-x3)*(x2-x4))*y2;
  term3 = ((x-x1)*(x-x2)*(x-x4))/((x3-x1)*(x3-x2)*(x3-x4))*y3;
  term4 = ((x-x1)*(x-x2)*(x-x3))/((x4-x1)*(x4-x2)*(x4-x3))*y4;
  y = term1+term2+term3+term4;
  return y;
}


