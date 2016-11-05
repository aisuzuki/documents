#include <stdio.h>
#include "permutation.h"

int sign(Permutation *exp)
{
   int i, j, change;
   change = 0;

   for (i=0; i<exp->expressonSize; i++) {
     if (exp->row[UPPER][i] 
        != exp->row[LOWER][i]) {
       for (j=1; exp->row[UPPER][i] 
           != exp->row[LOWER][i+j]; j++)
           if(j>exp->expressonSize) exit(NULL); 

     exp     = swap(exp, i, (i+j));
     change += 1;
        } /* for 'j' */
   }/* for 'i' */

   return  (change%2) ? EVEN : ODD;
}

Permutation *swap(Permutation *exp, int from, int to)
{
  int  i, buffer;
  
  buffer                = exp->row[LOWER][from]; 
  exp->row[LOWER][from] = exp->row[LOWER][to];  
  exp->row[LOWER][to]   = buffer;

#ifdef  TRACE

  printf("change! \n");
  printf("permutation %dth atom to %dth.\n",from+1, to+1);

  printf("now, permutation atoms are\n");
  for (i=0; i<exp->expressonSize; i++)
    printf("%dth is %d\n",i+1, exp->row[LOWER][i]);

#endif

  return exp;
}

/* this function for test. */
Permutation *init(Permutation *exp, int size)
{
   int i;
   exp->expressonSize = size;
   
   for (i=0; i<size; i++) 
     exp->row[UPPER][i] = (i+1);
 
 /* test data */
   exp->row[LOWER][0] = 1;
   exp->row[LOWER][1] = 4;
   exp->row[LOWER][2] = 2; 
   exp->row[LOWER][3] = 3;
   exp->row[LOWER][4] = 5;

#ifdef  TRACE

   printf("initing for calculation: \n");
   for (i=0; i<size; i++)
    printf("permutation %dth atom is %d\n",i+1, exp->row[LOWER][i]);
  
   printf("and permutations size is %d\n\n",exp->expressonSize);
   printf("calculation is starting... \n>\n");
#endif
   return exp;
}
/* file ends here */


