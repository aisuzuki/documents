#include <stdio.h>
#include <math.h>

int main()
{
  double  t, dt, a, omega;

  dt    = 1.0;
  a     = 5.0;  /* ½Ä¼´¤ÎÉý */
  omega = 50.0;

  for (t=0.0; t<100; t+=dt) {
    printf("%f %f \n", t, a*cos(omega*t));
  }
}
