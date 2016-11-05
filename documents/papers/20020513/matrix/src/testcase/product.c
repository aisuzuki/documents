#include <stdio.h>
#include "matrix.h"

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
/* file ends here */
