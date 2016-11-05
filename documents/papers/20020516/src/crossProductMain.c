#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "product.h"

int main(void)
{
  MessageSelector  *message;
  VectorComponent  *A, *B, *C;
  double  length, dth, th;
  int     theta;

  message  = newMessageSelector();
  A        = message->newVectorComponent();
  B        = message->newVectorComponent();
  C        = message->newVectorComponent();

  /* init A */
  A->x    = 20.0;

  /* init B */
  length  = 20.0;
  
  dth     = 0.0001;

   /* gnuplot setup */
   printf("set xrange [-50:50]\n");
   printf("set yrange [-50:50]\n");
   printf("set zrange [-600:600]\n");
   printf("set size square \n"); 

  /* pLaTeX */
  /*  printf("set term postscript eps enhanced\n"); */
  /* printf("set output \"crossproduct.eps\" \n");  */
  
   printf("set parametric\n");

  for (th=0.0, theta=0; th<90.0; th+=dth, theta+=1) {
    B->x = length * cos(th*(180.0/PI));
    B->y = length * sin(th*(180.0/PI));
    C = message->crossProduct(A, B);

    if (theta >= 360) 
     theta = 0;

/*    printf("set view 60, %d\n", theta); */

    printf("set label 1 \"x\"  at first  %d, first  0, first  0\n", (int)A->x); 
    printf("set label 2 \"y\"  at first  %d, first %d, first  0\n", (int)B->x, (int)B->y); 
    printf("set label 3 \"z\"  at first   0, first  0, first %d\n", (int)C->z); 
    printf("splot \"-\" w l \n");    
    printf("%f %f %f\n",A->thisX, A->thisY, A->thisZ);
    printf("%f %f %f\n",A->x, A->y, A->z);

    printf("%f %f %f\n",B->thisX, B->thisY, B->thisZ);
    printf("%f %f %f\n",B->x, B->y, B->z);

    printf("%f %f %f\n",B->x, B->y, B->z);
    printf("%f %f %f\n",B->x+A->x, B->y, B->z);
    printf("%f %f %f\n",A->x, A->y, A->z);

    printf("%f %f %f\n",C->thisX, C->thisY, C->thisZ);
    printf("%f %f %f\n",C->x, C->y, C->z);
    printf("e\n");    

    printf("set nolabel \n"); 
    fflush(stdout);
   }
  return 0;
}
