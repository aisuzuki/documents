#include <stdio.h>
#include <math.h>
#include "field.h"

int main(void)
{
   VectorField  vectorfield;
   FieldMaker  *fieldmaker;
   ScaleField   scolorfield;
   ScaleField  *scolorfieldP;
   int  i, j, dx, dy;

   fieldmaker   = newFieldMaker();
   scolorfieldP = fieldmaker->makeScaleField(&scolorfield);
   dx = 1.0;
   dy = 1.0;

   for (i=0, j=0; i<FIELD_SIZE; i++) {
     if ((i-1) < 0) {
      vectorfield.pointOf[i][j].x = 0.0;
      vectorfield.pointOf[i][j].y = 0.0;
      continue;
     } else if (i == FIELD_SIZE-1) {
      vectorfield.pointOf[i][j].x = 0.0;
      vectorfield.pointOf[i][j].y = 0.0;
      break;
     }
     for (j=0; j<FIELD_SIZE; j++) {
       if ((j-1) < 0) {
        vectorfield.pointOf[i][j].x = 0.0;
        vectorfield.pointOf[i][j].y = 0.0;
        continue;
       } else if (j == FIELD_SIZE-1) {
        vectorfield.pointOf[i][j].x = 0.0;
        vectorfield.pointOf[i][j].y = 0.0;
        break;
       }
       vectorfield.pointOf[i][j].x = (((scolorfieldP->potential[i-1][j] - scolorfieldP->potential[i][j]) / dx)
                                    + ((scolorfieldP->potential[i][j] - scolorfieldP->potential[i+1][j]) / dx))
                                     / 2;
       vectorfield.pointOf[i][j].y = (((scolorfieldP->potential[i][j-1] - scolorfieldP->potential[i][j]) / dy)
                                    + ((scolorfieldP->potential[i][j] - scolorfieldP->potential[i][j+1]) / dy))
                                     / 2;
     } /* for 'j' */
   } /* for 'i' */

for(;;) {
  printf("plot \"-\" w vector\n");
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
       printf("%d %d %10f %10f\n", i, j, -vectorfield.pointOf[i][j].y+i, vectorfield.pointOf[i][j].x+i);
     }
     printf("\n");
   }
  printf("e\n");
  }
   return 0;
}
