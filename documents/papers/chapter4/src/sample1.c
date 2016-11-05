#include <stdio.h>
#include <math.h>

main()
{
  double  lambda, y, t, dt;

  y      = 3114810.3;
  lambda = 0.03135;
  dt     = 0.01;

  for (t=0.0; t<1600; t+=dt) {
    printf("%lf %lf \n", t, -lambda*y*dt+y);
    y = -lambda*y*dt+y;
  }
}
