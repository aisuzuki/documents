#include <stdio.h>
#include "field.h"

int main(void) 
{
  ScaleField   scalefield, *scalefieldP;
  VectorField *vectorfield;
  FieldMaker  *fieldmaker;
  int i, j;

  fieldmaker  = newFieldMaker();
  scalefieldP = fieldmaker->makeScaleField(&scalefield);

  vectorfield = fieldmaker->makeVectorField(scalefieldP);

  for (i = 0; i < FIELD_SIZE; i++) { 
    if ((i - 1) < 0)
      continue;
    else if (i == FIELD_SIZE - 1)
      break;

    for (j = 0; j < FIELD_SIZE; j++) {
	    if ((j - 1) < 0)
	      continue;
	    else if (j == FIELD_SIZE - 1)
	      break;
	    printf ("%d %d %10f %10f\n", i, j, vectorfield->pointOf[i][j].x, vectorfield->pointOf[i][j].y);
	  }
    printf ("\n");
  }
  return 0;
}
