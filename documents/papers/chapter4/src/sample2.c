#include <stdio.h>
#include <math.h>

main()
{
  double  lambda, y, t, dt, gamma;

  y      = 3114810.3;
  lambda = 0.03135;
  dt     = 0.01;
  gamma  = 0.8;

  for (t=0.0; t<1600; t+=dt) {
    printf("%lf %lf \n", t, gamma*dt);
    y = gamma*dt;
  }
}
