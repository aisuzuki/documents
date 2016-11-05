#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "product.h"

quantity  lambda1(VectorComponent *A, VectorComponent *B)
{
  return ((A->x * B->x) + (A->y * B->y) + (A->z * B->z));
}

VectorComponent *lambda2(VectorComponent *A, VectorComponent *B)
{
  VectorComponent *com;
  MessageSelector *message;

  message  = newMessageSelector();
  com      = message->newVectorComponent();

  com->x = ((A->y * B->z) - (A->z * B->y));
  com->y = ((A->z * B->x) - (A->x * B->z));
  com->z = ((A->x * B->y) - (A->y * B->x));
  
  free(message);
  return com;
}


VectorComponent *lambda3(VectorComponent *A, VectorComponent *B, double theta) 
{
  MessageSelector *message;
  VectorComponent *C;
  quantity  buffer;

  message = newMessageSelector();
  C       = message->newUnitVectorComponent();

  buffer  = (sqrt(A->x*A->x + A->y*A->y + A->z*A->z));
  buffer *= (sqrt(B->x*B->x + B->y*B->y + B->z*B->z));
  buffer *= sin(theta);
  C->z    = C->z * buffer;

  free(message);
  return C;
} 

VectorComponent  *lambda4(void)
{
  VectorComponent  *com;
  
  com = (VectorComponent *)malloc(sizeof (VectorComponent));
 
  com->x     = com->y     = com->z     = 0.0;
  com->thisX = com->thisY = com->thisZ = 0.0;

  return com;
}

/* make an Unit vector */
VectorComponent  *lambda5(void)
{
  VectorComponent  *com;
  
  com = (VectorComponent *)malloc(sizeof (VectorComponent));
 
  com->z = 1.0;
  com->x = com->y = 0.0;
  com->thisX = com->thisY = com->thisZ = 0.0;

  return com;
}

MessageSelector  *newMessageSelector(void)
{
  MessageSelector *selector;

  selector = (MessageSelector *)malloc(sizeof (MessageSelector));
  
  selector->dotProduct              = lambda1;
  selector->crossProduct            = lambda2;
  selector->crossProductWithAngle   = lambda3;
  selector->newVectorComponent      = lambda4;
  selector->newUnitVectorComponent  = lambda5;
  
  return selector;
}

void InitDotproductTest(VectorComponent *A, VectorComponent *B)
{
  A->x = 10.0;
  B->x =  5.0;
  B->y = 10.0;
}

void InitCrossproductTest(VectorComponent *A, VectorComponent *B)
{
  A->x =   0.0;
  A->y =   0.0;
  B->x =   0.0;
  B->y =   0.0;
}

