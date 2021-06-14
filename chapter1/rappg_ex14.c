/* Coulomb exercise
Greg Rapp */
#include <stdio.h>
#include <math.h>
const double pi=3.141592653589793;
const double e0 = 8.85418782e-12;

double* findForce(double q1, double q2, double x2, double y2)
{
  /* calculate distance and force magnitude */
  double r = sqrt(pow(x2,2)+pow(y2,2));
  double f = (q1*q2)/(4*pi*e0*pow(r,2));
  /* calculate unit vector */
  double ux = pow(x2,2)/r;
  double uy = pow(y2,2)/r;
  /* return vector storing x and y force components */
  double xcomp = f*ux;
  double ycomp = f*uy;
  double pos[2] = {xcomp,ycomp};
  return pos;
}

int main()
{
  double x2=0.0,y2=0.0;
  double Q1=4.54,Q2=3.883;

  printf("\nThis program will print the x and y components of the Coulomb force on charge Q2\n");

  while(x2 == 0.0 && y2 == 0.0) {
      printf("\nEnter x,y coordinates for Q2, avoiding 0,0 > ");
      scanf("%lf,%lf",&x2,&y2);
      if(x2 == 0.0 && y2 == 0.0)
        printf("\nBoth x and y cannot be 0.0; please try again");
  }
  double* f = findForce(Q1, Q2, x2, y2);
  printf("Force in X direction: %e\nForce in Y direction: %e\n",f[0],f[1]);
  return(0);
}
