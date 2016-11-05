#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "field.h"

#define SQUARE(n)   (n*n)

/* for DEBUG  */
/*#define DEBUG */

ScaleField *lambda1(ScaleField *field)
{
  double dx, dy;
  int i, j, k, l, inck, incl, halfsize;

  if ((FIELD_SIZE % 2) == 0)
    halfsize = (FIELD_SIZE / 2);
  else
    halfsize = (FIELD_SIZE / 2)+1;

  dx = 1.0;
  dy = 1.0;
                        
  for (i=0, k=halfsize, inck=1; i<FIELD_SIZE; i++, k-=inck) { 
    for (j=0, l=halfsize, incl=1; j<FIELD_SIZE; j++, l-=incl) { 
      field->potential[i][j] = 1/ (sqrt(SQUARE((k+dx)) + SQUARE((l+dy))));

      if(l==0)
       incl *= -1;
    }
    if(k==0)
     inck *= -1;
  }
  return field;
}

VectorField *lambda2(ScaleField *scalefield)
{
  VectorField *vectorfield;
  int  i, j, dx, dy;

  vectorfield = (VectorField *)malloc(sizeof (VectorField));
  dx = 1.0;
  dy = 1.0;
  
  for (i=0, j=0; i<FIELD_SIZE; i++) {
    if ((i-1) < 0) {
      vectorfield->pointOf[i][j].x = 0.0;
      vectorfield->pointOf[i][j].y = 0.0;
      continue;
    } else if (i == FIELD_SIZE-1) {
      vectorfield->pointOf[i][j].x = 0.0;
      vectorfield->pointOf[i][j].y = 0.0;
      break;
    }
    for (j=0; j<FIELD_SIZE; j++) {
      if ((j-1) < 0) {
        vectorfield->pointOf[i][j].x = 0.0;
        vectorfield->pointOf[i][j].y = 0.0;
        continue;
      } else if (j == FIELD_SIZE-1) {
        vectorfield->pointOf[i][j].x = 0.0;
        vectorfield->pointOf[i][j].y = 0.0;
        break;
    }
    vectorfield->pointOf[i][j].x = 
                (((scalefield->potential[i-1][j] - scalefield->potential[i][j]) / dx)
               + ((scalefield->potential[i][j] - scalefield->potential[i+1][j]) / dx))
               / 2;
    vectorfield->pointOf[i][j].y = 
                (((scalefield->potential[i][j-1] - scalefield->potential[i][j]) / dy)
               + ((scalefield->potential[i][j] - scalefield->potential[i][j+1]) / dy))
               / 2;
    } /* for 'j' */
  } /* for 'i' */

  return vectorfield;
}

FieldMaker *newFieldMaker(void)
{
  FieldMaker *fm;

  fm = (FieldMaker *)malloc(sizeof (FieldMaker));

  fm->makeScaleField  = lambda1;
  fm->makeVectorField = lambda2;

  return fm;
}

#ifdef DEBUG
int main()
{
  ScaleField   field;
  FieldMaker  *fieldmaker;
  ScaleField  *fieldp;
  VectorField *vectorfield;
  int  i, j;

  fieldmaker = newFieldMaker();
  fieldp = fieldmaker->makeScaleField(&field);

  vectorfield = fieldmaker->makeVectorField(fieldp);
/*
  for (i=0; i<FIELD_SIZE; i++) {
    for (j=0; j<FIELD_SIZE; j++) {
      printf("%d %d %10f \n",i, j, fieldp->potential[i][j]);
    }
    printf("\n");
  }
*/
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
#endif

/* file ends here */
