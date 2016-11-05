#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "field.h"

#define  SQUARE(n) (n*n) 

ScaleField *makeScaleField(ScaleField *scalefield, 
                           anElectron  electrons)
{
  int i, j, k, l, inck, incl, thisX, thisY;
  
  thisX = (FIELD_SIZE / 2) + (int)(electrons.x);
  thisY = (FIELD_SIZE / 2) + (int)(electrons.y);
  
  for (i=0, k=thisY, inck=1; i<FIELD_SIZE; i++, k-=inck) {
    for (j=0, l=thisX, incl=1; j<FIELD_SIZE; j++, l-=incl) {
      if ((l==0) && (k==0)) 
       scalefield->potential[i][j] = 0.0;
      else  
       scalefield->potential[i][j] += (electrons.q
                                    / (sqrt(SQUARE(l) + SQUARE(k))));
      if(l==0)
       incl *= -1;
    } /* for 'j' */
    if(k==0)
     inck *= -1;
  } /* for 'i' */

  return scalefield;
}

ScaleField *newScaleField(void)
{
  ScaleField  *scalefield;

  scalefield = (ScaleField *)malloc(sizeof (ScaleField));

  return  clearScaleField(scalefield);
}

ScaleField *clearScaleField(ScaleField  *scalefield)
{
  int i, j;

  for (i=0; i<FIELD_SIZE; i++)
    for (j=0; j<FIELD_SIZE; j++)
      scalefield->potential[i][j] = 0.0;

  return scalefield;
}
