/*
  Greg Rapp
  11/11/2020
  exercise 9.1
*/
#include <stdio.h>
#include <math.h>
double* findAB(double xdat[],double ydat[]);

const int n = 50;

int main(){
  FILE *in;
  double x[n], y[n], *ans;
  int count = 0;
  in = fopen("data91.dat","r");
  while (fscanf(in, "%lf %lf",&x[count],&y[count]) != EOF){
    count++;
  }
  ans = findAB(x,y);
  printf("A = %3.5lf, A err = %3.5lf, B = %3.5lf, Berr = %3.5lf\n",ans[0],ans[2],ans[1],ans[3]);
}

double * findAB(double xdat[],double ydat[]){
  double a,b,ae,be,s,sx,sxx,sy,sxy,sig,delta,chi,vara,varb,se;
  double ans[4];
  int i;
  sig = 1;
  chi = 0;
  for (i = 0; i < n; i++){
    s += 1 / (sig * sig);
    sx += xdat[i] / (sig * sig);
    sxx += (xdat[i] * xdat[i]) / (sig * sig);
    sy += ydat[i] / (sig * sig);
    sxy += (xdat[i] * ydat[i]) / (sig * sig);
  }
  delta = (s * sxx) - (sx * sx);
  a = (sxx * sy - sx * sxy) / delta;
  b = (s * sxy - sx * sy) / delta;
  for (i = 0; i < n; i++){
    chi += pow(((ydat[i] - a - b*xdat[i])/sig),2);
  }
  vara = sxx/delta;
  varb = s/delta;
  se = chi/(n-2);
  ae = sqrt(se) * vara;
  be = sqrt(se) * varb;
  ans[0] = a;
  ans[1] = b;
  ans[2] = ae;
  ans[3] = be;
  return ans;
}
