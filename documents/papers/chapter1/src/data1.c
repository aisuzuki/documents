#include <stdio.h>
#include <math.h>

int main()
{
  double  data[] = {9.7, 13.0, 17.4, 23.0, 30.2,
                    38.1, 49.9, 62.4, 76.5, 91.6,
                    107.0, 122.0};

  int i;

  for (i=0; i<12; i++) {
    printf("%d %f\n", i, data[i]);
  }
}
