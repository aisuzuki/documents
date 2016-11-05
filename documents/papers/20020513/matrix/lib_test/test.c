#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int 
main (int argc, char **argv)
{

   FILE   *data;
   int i, j, l, k, m, t, size, brac;
   Matrix matrix[10];

   char  readData[MATRIX_SIZE];
   char  numBuffer[15];
   int   dataBuffer[MATRIX_SIZE];

   if ((data = fopen(*(argv+1), "r")) == NULL) {
      printf("error: can't open file ;exit(1)\n");
      exit(1);
   }
   m=0;

  do {
   
   for (i=0, l=0, j=0, brac=0, matrix[m].rowsize=0;
       (fgets(readData, MATRIX_SIZE, data)) != NULL; i++, m++) {

       while (readData[j] != ')') {

          if (tokenp(readData[j])) {
              if (readData[j] == '(')
               brac++;

               j++;
          } else {
             for (t=0; !tokenp(readData[j]); j++, t++) {
                  numBuffer[t] = readData[j];
             }
              numBuffer[t] = '\0';
               
              dataBuffer[l] = atoi(numBuffer);
              l++; 
          } 

      } /* while */

      brac--;
      for (k=0; k<l; k++) {
         matrix[m].row[i][k] = dataBuffer[k];
         printf("%d\n",matrix[m].row[i][k]);
      } /* for */

      matrix[m].rowsize += 1;
      j=0, l=0;

   } /* for */  
   matrix[m].columnsize = l;

 }  while (brac == 0);

  fclose(data);

} /* main */

/* file ends here */
