#include <stdio.h>
#include "matrix.h"

// #define DEBUG

Matrix *lambda4(Matrix *mat, Matrix *ans)
{
  int i, j, k, l;

  for (i=0, l=0; i<mat->rowsize; i++, l++) 
    for (j=0, k=0; j<mat->columnsize; j++, k++) 
        ans->row[k][l] = mat->row[i][j];

    ans->rowsize    = mat->columnsize;
    ans->columnsize = mat->rowsize;
    return ans;
}


#ifdef DEBUG
int main(){

  Matrix  matrixA = {2, 4, {{1, 2, 3, 4}, {5, 6, 7, 8}}};
  Matrix  answer;
  Matrix *ap, *A;
  int i, j;
  ap = &answer;
  A  = &matrixA;

  ap = oppmove(A, ap);

  printf("answer:\n");
  for (i=0; i<ap->rowsize; i++) {
     for (j=0; j<ap->columnsize; j++) {
       printf("%4d", ap->row[i][j]);
    }
    printf("\n");
  }
  
  printf("もともと\n");
  for (i=0; i<A->rowsize; i++) {
     for (j=0; j<A->columnsize; j++) {
       printf("%4d",A->row[i][j]);
    }
    printf("\n");
 }
}
#endif 
/* file ends here */
