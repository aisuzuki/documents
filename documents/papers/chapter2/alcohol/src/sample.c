#include <stdio.h>

main()
{
  double R, b, db, k;

  db = 0.01;
  R  = 1.0;
  k  = 21.4;

  for (b=0.01; b<0.5; b+=db) {
    printf("%f %f\n", b, k*R*db+R); 
    R = k*R*db+R;
  }
}
