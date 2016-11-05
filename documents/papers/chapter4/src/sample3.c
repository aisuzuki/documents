#include <stdio.h>
#include <math.h>

main()
{
  double  lambda, y0, t, dt, gamma;

  y0     = 3114810.3;
  lambda = 0.03135;
  dt     = 0.01;
  gamma  = 0.8;

  for (t=0.0; t<800; t+=dt) {
    printf("%lf %lf \n", t, gamma/lambda + (y0 - gamma/lambda)*exp(-lambda*t) );
  }
}
