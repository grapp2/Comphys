/*
Greg Rapp
EX 3.2
9/9
*/
#include <stdio.h>
double doit(double T){
  T = T * 2.5;
  return T;
}
int main(){
  double T = 100;
  double ans = doit(T);
  printf("%lf\n",ans);
}
