#include <stdio.h>
#include <math.h>
#include "field.h"

int main()
{
  ScaleField  *scalefield;
  VectorField *vectorfield;
  anElectron  electrons;
  int i, j;
  
  scalefield  = newScaleField();
  vectorfield = newVectorField();

  electrons.q  =  1.0; 
  electrons.x  =  0.0; 
  electrons.y  =  0.0; 
  electrons.vx =  0.0; 
  electrons.vy =  0.0; 
 
  scalefield  = makeScaleField(scalefield, electrons);
  vectorfield = makeVectorField(scalefield, vectorfield);

 /* test for scalefield 
  for (i=0; i<FIELD_SIZE; i++) { 
    for (j=0; j<FIELD_SIZE; j++) { 
      printf("%d %d %f\n", j, i, scalefield->potential[i][j]);
    }
    printf("\n");
   }
    */

 /* test for vectorfield    */
  for (i=0; i<FIELD_SIZE; i++) { 
    for (j=0; j<FIELD_SIZE; j++) { 
      printf("%d %d %f %f\n", j, i, vectorfield->pointOf[i][j].x, vectorfield->pointOf[i][j].y);
    }
    printf("\n");
  }
  return 0;
}
