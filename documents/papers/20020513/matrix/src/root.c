#include <stdio.h>
#include "matrix.h"

int main()
{
  Matrix  matrixA = {4, 4, {{ 1, 2, 3, 4}, 
                            { 5, 6, 7, 8},
                            { 9,10,11,12}, 
                            {13,14,15,16}}};
  /* √±∞Ãπ‘ŒÛ */
  Matrix  matrixE = {4, 4, {{1, 0, 0, 0},
                            {0, 1, 0, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 1} }};

  Matrix  answer1, answer2, buffer;
  Matrix  *ans1, *ans2, *A, *E, *buf;
  int   i, j;
  
  A    = &matrixA;
  E    = &matrixE;
  ans1 = &answer1;
  ans2 = &answer2;
  buf  = &buffer;

 /*------------
    A*E 
   ------------*/
  ans1 = product(A, E, ans1);

 /*------------
    E*A 
   ------------*/
  ans2 = product(E, A, ans2);

  printf("A*E =\n");
  for (i=0; i<ans1->rowsize; i++) {
    for (j=0; j<ans1->columnsize; j++) {
      printf("%6d", ans1->row[i][j]);
   }
   printf("\n");
 }

  printf("E*A =\n");
  for (i=0; i<ans2->rowsize; i++) {
    for (j=0; j<ans2->columnsize; j++) {
      printf("%6d", ans2->row[i][j]);
   }
   printf("\n");
 }
 return 0;
}
/* file ends here */
