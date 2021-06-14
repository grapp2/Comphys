/*
  Greg Rapp
  11/11/2020
  exercise 9.3
*/
#include <stdio.h>
#include "comphys.c"
#include "comphys.h"
int main(){
  int n = 3;
  int m = 1;
  float **a,**b;
  int i;
  a = matrix(1,n,1,n);
  b = matrix(1,n,1,m);
  a[1][1] = 1;
  a[1][2] = 5;
  a[1][3] = 3;
  a[2][1] = 2;
  a[2][2] = 1;
  a[2][3] = 9;
  a[3][1] = 3;
  a[3][2] = 8;
  a[3][3] = 8;

  b[1][1] = 5;
  b[2][1] = 2;
  b[3][1] = 1;

  gaussj(a,n,b,m);
  for (i = 1; i <= n; i++){
    printf("x[%d] = %f\n",i,b[i][1]);
  }
}
