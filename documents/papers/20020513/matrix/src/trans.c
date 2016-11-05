#include <stdio.h>
#include "matrix.h"

int main()
{
  Matrix  matrixA = {4, 4, {{ 1, 2, 3, 4}, 
                            { 5, 6, 7, 8},
                            { 9,10,11,12}, 
                            {13,14,15,16}}};

  Matrix  matrixB = {4, 4, {{ 1, 2, 3, 4},
                            { 5, 6, 7, 8},
                            { 9,10,11,12},
                            {13,14,15,16}}};

  Matrix  matrixC = {4, 4, {{ 1, 2, 3, 4}, 
                            { 5, 6, 7, 8},
                            { 9,10,11,12}, 
                            {13,14,15,16}}};

  Matrix  answer1, answer2, buffer;
  Matrix  *ans1, *ans2, *A, *B, *C, *buf;
  int   i, j;
  
  A    = &matrixA;
  B    = &matrixB;
  C    = &matrixC;
  ans1 = &answer1;
  ans2 = &answer2;
  buf  = &buffer;

 /*------------
    (AB)C 
   ------------*/
  buf  = product( A, B, buf);
  ans1 = product(buf, C, ans1);

 /*------------
    A(BC)
   ------------*/
  buf  = product(  B, C, buf);
  ans2 = product(buf, A, ans2);

  printf("(AB)C =\n");
  for (i=0; i<ans1->rowsize; i++) {
    for (j=0; j<ans1->columnsize; j++) {
      printf("%6d", ans1->row[i][j]);
   }
   printf("\n");
 }

  printf("A(BC) =\n");
  for (i=0; i<ans2->rowsize; i++) {
    for (j=0; j<ans2->columnsize; j++) {
      printf("%6d", ans2->row[i][j]);
   }
   printf("\n");
 }
 return 0; 
}
/* file ends here */
