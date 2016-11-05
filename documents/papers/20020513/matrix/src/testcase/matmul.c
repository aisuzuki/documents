#include <stdio.h>
#include "matrix.h"

int main()
{
  Matrix  matrixA = {2, 4, {{1, 2, 3, 4}, {5, 6, 7, 8}}};
  Matrix  answer;
  Matrix  *ans, *A;
  int     multipl;
  int i, j;

  A   = &matrixA;
  ans = &answer;
  multipl = 5;

  ans = matmul(A, ans, multipl);

  for (i=0; i<ans->rowsize; i++) {
    for (j=0; j<ans->columnsize; j++) {
      printf("%4d", ans->row[i][j]);
    }
    printf("\n");
  }
}
