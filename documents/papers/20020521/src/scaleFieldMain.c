#include <stdio.h>
#include "field.h"

int main()
{
  ScaleField   scalefield, *scalefieldP;
  FieldMaker  *fieldmaker;
  
  int  i, j;
  fieldmaker  = newFieldMaker();
  scalefieldP = fieldmaker->makeScaleField(&scalefield);

  for (i=0; i<FIELD_SIZE; i++) {
    for (j=0; j<FIELD_SIZE; j++) {
      printf("%d %d %10f \n",i, j, scalefieldP->potential[i][j]);
    }
    printf("\n");
  }
  return 0;
}
