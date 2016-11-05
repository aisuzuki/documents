#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "product.h"

int main(void)
{
  MessageSelector  *message;
  VectorComponent  *A, *B;
  quantity         dotproduct;
  double           length, dth, th;

  message = newMessageSelector();
  A       = message->newVectorComponent();
  B       = message->newVectorComponent();
  
  A->x    = 40.0;
  length  = 40.0;
   
  dth     = 0.0001;

  /* gnuplot setup */
  printf("set xrange [-50:50]\n");
  printf("set yrange [-50:50]\n");
  printf("set size square \n");

  /* method for pLaTeX */
  /*  printf("set term postscript eps enhanced\n");
      printf("set output \"dotproduct1.eps\"\n");   */

  for (th=0.0; ; th+=dth) {
   
    if ((cos(th*(180.0/PI)) < 0.0) ||
        (sin(th*(180.0/PI)) > 1.0))
      dth *= -1.0;

    dotproduct = message->dotProduct(A, B);

    printf("set label 1 \"x\"  at first  %d, first  0 \n", (int)A->x);
    printf("set label 2 \"y\"  at first  %d, first %d \n", (int)(length*cos(th*(180.0/PI)))
                                                         , (int)(length*sin(th*(180.0/PI))));
    
    printf("plot \"-\" w l \n");
    printf("%f  %f \n", A->thisX, A->thisY); 
    printf("%f  %f \n", A->x, A->y); 

    printf("%f %f \n",B->thisX, B->thisY);
    printf("%f %f \n",length*cos(th*(180.0/PI)), length*sin(th*(180.0/PI)));

    printf("%f %f \n",length*cos(th*(180.0/PI)), length*sin(th*(180.0/PI)));
    printf("%f %f \n",length*cos(th*(180.0/PI)),0.0);

    printf("%f %f \n",0.0, 0.0);
    printf("%f %f \n",0.0, -length*cos(th*(180.0/PI)));

    printf("%f %f \n",0.0, -length*cos(th*(180.0/PI)));
    printf("%f %f \n", A->x,-length*cos(th*(180.0/PI)));

    printf("%f %f \n", A->x,-length*cos(th*(180.0/PI)));
    printf("%f %f \n", A->x, 0.0);

    printf("e \n");
    printf("set nolabel \n");
  }
  return 0;
}
