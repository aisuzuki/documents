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

  Matrix  answer1, answer2, buffer1, buffer2, buffer3;
  Matrix  *ans1, *ans2, *A, *B, *C, *buf1, *buf2, *buf3;
  int   i, j;
  
  A    = &matrixA;
  B    = &matrixB;
  C    = &matrixC;
  ans1 = &answer1;
  ans2 = &answer2;
  buf1 = &buffer1;
  buf2 = &buffer2;
  buf3 = &buffer3;

 /*------------
    (A+B)C 
   ------------*/
  buf1 = matplus( A, B, buf1);
  ans1 = product(buf1, C, ans1);

 /*------------
    AC+BC
   ------------*/
  buf2 = product(A, C, buf2);
  buf3 = product(B, C, buf3);

  ans2 = matplus(buf2, buf3, ans2);

  printf("(A+B)C =\n");
  for (i=0; i<ans1->rowsize; i++) {
    for (j=0; j<ans1->columnsize; j++) {
      printf("%6d", ans1->row[i][j]);
   }
   printf("\n");
 }

  printf("AC+BC =\n");
  for (i=0; i<ans2->rowsize; i++) {
    for (j=0; j<ans2->columnsize; j++) {
      printf("%6d", ans2->row[i][j]);
   }
   printf("\n");
 }
 return 0;
}
/* file ends here */
