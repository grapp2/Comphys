/*
Greg Rapp
EX 3.1
9/9
*/
#include <stdio.h>
void doit(double *T){
  *T = *T * 2.5;
}
int main(){
  double T = 100;
  doit(&T);
  printf("%lf\n",T);
}

