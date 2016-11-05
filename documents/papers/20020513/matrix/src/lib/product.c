#include <stdio.h>
#include "matrix.h"

//#define DEBUG

Matrix *product(Matrix *A, Matrix *B, Matrix *ans)
{
   Matrix  buffer;
   Matrix *buf;
   int i, j;
   buf = &buffer;

   if (A->columnsize != B->rowsize) 
    return NIL;
   
   buf = oppmove(B, buf);
   
   for (i=0; i<A->rowsize; i++) 
     for (j=0; j<B->columnsize; j++) 
       ans->row[i][j] = naiseki(A->row[i], buf->row[j], A->columnsize);
  
   ans->rowsize    = A->rowsize;
   ans->columnsize = B->columnsize;
   return ans;
}

int car(int V[])
{
  return V[0];
}

int *cdr(int V[])
{
  return (V+1);
}

int naiseki(int *VA, int *VB, int size)
{
    int answer;
    int i;
    answer = 0;

    for (i=0; i<size; i++) {
      answer += car(VA+i) * car(VB+i);
    }
    return answer;
}

#ifdef DEBUG
int main()
{
  Matrix  matrixA = {2, 4, {{1, 2, 3, 4}, {5, 6, 7, 8}}};
  Matrix  matrixB = {4, 2, {{1, 2}, {3, 4}, {5, 6}, {7, 8}}};
  Matrix  answer;
  Matrix  *ans, *A, *B;
  int   i, j;
  
  A   = &matrixA;
  B   = &matrixB;
  ans = &answer;
 
  ans = product(A, B, ans);

  for (i=0; i<ans->rowsize; i++) {
    for (j=0; j<ans->columnsize; j++) {
      printf("%4d", ans->row[i][j]);
   }
   printf("\n");
 }
}
#endif 

/* file ends here */
