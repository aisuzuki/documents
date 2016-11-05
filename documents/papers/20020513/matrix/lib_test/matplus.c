#include <stdio.h>
#include "matrix.h"

// #define DEBUG

Matrix *lambda2(Matrix *A, Matrix *B, Matrix *ans)
{
   int i, j;

   for (i=0; i<A->rowsize; i++) 
     for (j=0; j<A->columnsize; j++) 
       ans->row[i][j] = A->row[i][j] + B->row[i][j];

   ans->rowsize    = A->rowsize;
   ans->columnsize = A->columnsize;
   return ans;
}


#ifdef DEBUG
int main()
{
   Matrix matrixA = {2, 4, {{1, 2, 3, 4}, {5, 6, 7, 8}}};
   Matrix matrixB = {2, 4, {{1, 2, 3, 4}, {5, 6, 7, 8}}};
   Matrix matrixC = {2, 4, {{1, 2, 3, 4}, {5, 6, 7, 8}}};
   Matrix *Answer1, *Answer2, *A, *B, *C, *buf;
   int i, j;
   
   Answer1 = (Matrix *) malloc (sizeof (Matrix));
   Answer2 = (Matrix *) malloc (sizeof (Matrix));
   buf     = (Matrix *) malloc (sizeof (Matrix));
   A = &matrixA;
   B = &matrixB;
   C = &matrixC;

   buf     = matplus(A, B, buf);
   Answer1 = matplus(C, buf, Answer1);

   buf     = matplus(B, C, buf);
   Answer2 = matplus(A, buf, Answer2);

   printf("Answer1:\n");
   for (i=0; i<A->rowsize; i++) {
     for (j=0; j<A->columnsize; j++)  {
       printf("%3d ",Answer1->row[i][j]);
     }
     printf("\n");
  }

   printf("Answer2:\n");
   for (i=0; i<A->rowsize; i++) {
     for (j=0; j<A->columnsize; j++)  {
       printf("%3d ",Answer2->row[i][j]);
     }
     printf("\n");
  }
}

#endif

/* file ends here */
