#include <stdio.h>
#include <math.h>
#include "field.h"

#define SQARE(n) ((n) * (n))

int main()
{
  ScaleField  *sfield;
  VectorField *vfield;
  anElectron  *e;
  int i, j;
  double dx, dy;
  double r;
  nx = 20;
  ny = 20;

  dx = FIELD_SIZE / (double)nx;
  dy = FIELD_SIZE / (double)ny;
  
  sfield  = newScaleField();
  vfield = newVectorField();

  e = initElectrons(2, "","");

  sfield = makeScaleField(sfield, e);
  vfield = makeVectorField(sfield, vfield);

 /* test for sfield      
  for (i=0; i<ny; i++) { 
    for (j=0; j<nx; j++) { 
      printf("%f %f %f\n", (double)j * dx + (dx * 0.5)
                         , (double)i * dy + (dy * 0.5), sfield->potential[i][j]);
    }
    printf("\n");
  }
 */

 /* test for vfield    */
  for (i=1; i<ny-1; i++) { 
    for (j=1; j<nx-1; j++) { 
      r = sqrt(SQARE(vfield->pointOf[i][j].x) + SQARE(vfield->pointOf[i][j].y));
      printf("%f %f %f %f\n", (double)j * dx + (dx * 0.5), 
                              (double)i * dy + (dy * 0.5), 
                              2.0 * vfield->pointOf[i][j].x / r, 
                              2.0 * vfield->pointOf[i][j].y / r);
    }
    printf("\n");
  }
  return 0;
}
