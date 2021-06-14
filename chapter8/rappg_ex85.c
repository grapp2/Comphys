/*
  Greg Rapp
  11/4/2020
  exercise 8.5
*/
#include <stdio.h>
#include <math.h>
double pi = 3.14159;
int main()
{
  double x1,y1,z1,x2,y2,z2,slope,yint;
  double k1,k2,k3,k4,l1,l2,l3,l4;
  double dx = 0.1;
  int i = 0;
  /* initial conditions */
  x1 = 0.0;
  y1 = pi/(double) 4;
  z1 = 0.0;
  /* Integrate using fourth-order Runge Kutta from x=0 to x=1 */
  while(i <= 4) {
    printf("x = %3.1f y = %f z = %f\n",x1,y1,z1);
    if(x1 == 1.0) break;
    k1 = z1*dx;
    l1 = -sin(y1)*dx;

    k2 = (z1+0.5*l1)*dx;
    l2 = -sin(y1+0.5*k1)*dx;

    k3 = (z1+0.5*l2)*dx;
    l3 = -sin(y1+0.5*k2)*dx;

    k4 = (z1+l3)*dx;
    l4 = -sin(y1+k3)*dx;
    y2 = y1 + (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
    z2 = z1 + (l1 + 2.0*l2 + 2.0*l3 + l4)/6.0;
    x2 = x1 + dx;
    if((z2 < 0 && z1 >= 0) || (z1 < 0 && z2 >= 0)){
      i++;
    }
    if (i <= 4){
      x1 = x2;
      y1 = y2;
      z1 = z2;
    }
  }
  slope = (x2-x1)/(z2-z1);
  yint = -1*(slope*z2)+x2;
  printf("Calculated period: %lf\n",yint);
  return(0);
}
