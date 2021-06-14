/*
Greg Rapp
EX 3.3
9/9
*/
#include <stdio.h>
double T = 100;
void doit(){
  T = T * 2.5;
}
int main(){
  doit();
  printf("%lf\n",T);
}
