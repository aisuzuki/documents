#include <stdio.h>
#include "matrix.h"

#define DEBUG

Matrix *lambda5(Matrix *A, Matrix *B, Matrix *ans)
{
   MatrixOperator *operator;
   Matrix buffer;
   Matrix *buf;
   int i, j;

   operator = newMatrixOperator();
   buf = &buffer;

   if (A->columnsize != B->rowsize) 
    return NIL;
   
   buf = operator->oppmove(B, buf);
   
   for (i=0; i<A->rowsize; i++) 
     for (j=0; j<B->columnsize; j++) 
       ans->row[i][j] = naiseki(A->row[i], buf->row[j], A->columnsize);
  
   ans->rowsize    = A->rowsize;
   ans->columnsize = B->columnsize;
   return ans;
}

#ifdef DEBUG
int main()
{
  Matrix          matrixA = {2, 4, {{1, 2, 3, 4}, {5, 6, 7, 8}}};
  Matrix          matrixB = {4, 2, {{1, 2}, {3, 4}, {5, 6}, {7, 8}}};
  Matrix          *ans, *A, *B;
  MatrixOperator  *operator;
  int     i, j;
  
  A        = &matrixA;
  B        = &matrixB;
  operator = newMatrixOperator();

  ans = operator->product(A, B, ans);

  for (i=0; i<ans->rowsize; i++) {
    for (j=0; j<ans->columnsize; j++) {
      printf("%4d", ans->row[i][j]);
   }
   printf("\n");
 }
}
#endif 

/* file ends here */
