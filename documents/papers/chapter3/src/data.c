#include <stdio.h>

main()
{
  double t[] = {6.5, 17.3, 29.0, 41.3, 53.7, 67.7, 
              83.5, 101.0, 120.7, 146.5, 179.7 }; 
  
  int i, j;

  for (i=11, j=0; i>0; i--, j++) {
    printf("%lf %d\n", t[j], i);
  }
}

