#include <stdio.h>
#include <math.h>

main()
{
  double  h, t, ti, c;
  c = 11;

  for (t=6.5; t<170; t+=0.1) {
    h = -(2.0/3.0)*(0.7/7.0)*t+c;
    printf("%lf %lf \n", t, h);
  }
}
