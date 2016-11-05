#include <stdio.h>
#include "matrix.h"
// #define  DEBUG

int car(int V[])
{
  return V[0];
}

int *cdr(int V[])
{
  return (V+1);
}

MatrixOperator *newMatrixOperator(void)
{
  MatrixOperator  *operator;

  operator = (MatrixOperator *) malloc (sizeof (MatrixOperator));

  operator->matmul   = lambda1;
  operator->matplus  = lambda2;
  operator->mattake  = lambda3;
  operator->oppmove  = lambda4;
  operator->product  = lambda5;

  return operator;
}

#ifdef DEBUG
int main()
{
  int VectorA[3] = {1, 2, 3};
  int VectorB[3] = {1, 2, 3};
  
  printf("%d\n", car(VectorA));
  printf("%d\n", car(cdr(VectorA)));

  printf("%d", naiseki(VectorA, VectorB, 3, 0));

}
#endif

/* file ends here */
