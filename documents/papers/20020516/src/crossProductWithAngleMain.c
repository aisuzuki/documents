#include <stdio.h>
#include <stdlib.h>
#include "product.h"

int main(void)
{
  MessageSelector  *message;
  /* 'C' is Unit vector in direction z */
  VectorComponent  *A, *B, *C;
  double            theta;

  message = newMessageSelector();
  A       = message->newVectorComponent();
  B       = message->newVectorComponent();

  theta = 30.0;

  InitCrossproductTest(A, B);

  C = message->crossProductWithAngle(B, A, theta);

  printf("%f %f %f\n",A->x, A->y, A->z);
  printf("%f %f %f\n",B->x, B->y, B->z);
  printf("%f %f %f\n",C->x, C->y, C->z);

  return 0;
}
