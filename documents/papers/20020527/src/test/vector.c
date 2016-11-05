#include <stdio.h>
#include <math.h>
#include "../field.h"

int main(void)
{
   VectorField *vectorfield;
   ScaleField  *scalefield;
   anElectron  *electrons;
   int  i, j, dx, dy;
  
   vectorfield = newVectorField(); 
   scalefield  = newScaleField(); 
   electrons   = initElectrons(10);
   scalefield  = makeScaleField(scalefield, electrons, 10);
   dx = 1.0;
   dy = 1.0;

   for (i=0, j=0; i<FIELD_SIZE; i++) {
     if ((i-1) < 0) {
      continue;
     } else if (i == FIELD_SIZE-1) {
      break;
     }
     for (j=0; j<FIELD_SIZE; j++) {
       if ((j-1) < 0) {
        continue;
       } else if (j == FIELD_SIZE-1) {
        break;
       }
       vectorfield->pointOf[i][j].x = (((scalefield->potential[i-1][j] - scalefield->potential[i][j]) / dx)
                                    + ((scalefield->potential[i][j] - scalefield->potential[i+1][j]) / dx))
                                     / 2;
       vectorfield->pointOf[i][j].y = (((scalefield->potential[i][j-1] - scalefield->potential[i][j]) / dy)
                                    + ((scalefield->potential[i][j] - scalefield->potential[i][j+1]) / dy))
                                     / 2;
     } /* for 'j' */
   } /* for 'i' */

   for (i=0; i<FIELD_SIZE; i++) {
     if ((i-1) < 0) 
      continue;  
      else if (i == FIELD_SIZE-1) 
      break;
     
     for (j=0; j<FIELD_SIZE; j++) {
       if ((j-1) < 0) 
        continue;
       else if (j == FIELD_SIZE-1) 
        break;
       printf("%d %d %10f %10f\n", i, j, vectorfield->pointOf[i][j].x, vectorfield->pointOf[i][j].y);
     }
     printf("\n");
   }
   return 0;
}
