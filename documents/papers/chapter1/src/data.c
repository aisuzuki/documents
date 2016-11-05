#include <stdio.h>
#include <math.h>

int main()
{
  double  data[] = {3.9, 5.3, 7.2, 9.6, 12.9,
                    17.1, 23.2, 31.4, 38.6, 50.2,
                    62.9, 76.0, 92.0, 106.5, 123.2};

  int i;

  for (i=0; i<15; i++) {
    printf("%d %f\n", i, data[i]);
  }
}
