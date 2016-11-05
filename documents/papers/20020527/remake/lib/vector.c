#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "field.h"

VectorField *newVectorField(void)
{
  VectorField  *vectorfield;
  int i, j;

  vectorfield = (VectorField *)malloc(sizeof (VectorField));

  for (i=0; i<FIELD_SIZE; i++) {
    for (j=0; j<FIELD_SIZE; j++) {
      vectorfield->pointOf[i][j].x = 0.0;
      vectorfield->pointOf[i][j].y = 0.0;
    }
  }
  return vectorfield;
}

VectorField *makeVectorField(ScaleField  *scalefield,
                             VectorField *vectorfield)
{
  int     i, j;
  double  upY, downY, leftX, rightX; 

  /* Because 'dx' and 'dy' are arrangement number,          */
  /* didnt divide each 'differentiated' potentials by these.*/
  
  for (i=0; i<FIELD_SIZE; i++) {
    for (j=0; j<FIELD_SIZE; j++) {
    
      if ((i==0) && (j==0)) {                       /* +-------   */
        upY    = scalefield->potential[i+1][j];     /* |@| | |    */
        downY  = scalefield->potential[i+1][j];     /* +-+-+-+    */
        leftX  = scalefield->potential[i][j+1];     /* | | | |    */
        rightX = scalefield->potential[i][j+1];     /*            */

      } else if ((i==FIELD_SIZE) &&
                 (j==FIELD_SIZE))   {               /*   | | | | */ 
        upY    = scalefield->potential[i-1][j];     /*   +-+-+-+ */
        downY  = scalefield->potential[i-1][j];     /*   | | |@| */
        leftX  = scalefield->potential[i][j-1];     /*  -------+ */
        rightX = scalefield->potential[i][j-1];     /*           */

      } else if ((i==0) && (j==FIELD_SIZE)) {       /*  -------+ */
        upY    = scalefield->potential[i+1][j];     /*   | | |@| */
        downY  = scalefield->potential[i+1][j];     /*   +-+-+-+ */
        leftX  = scalefield->potential[i][j-1];     /*   | | | | */
        rightX = scalefield->potential[i][j-1];     /*           */

      } else if ((i==FIELD_SIZE) && (j==0)) {       /* | | | |   */
        upY    = scalefield->potential[i-1][j];     /* +-+-+-+   */
        downY  = scalefield->potential[i-1][j];     /* |@| | |   */
        leftX  = scalefield->potential[i][j+1];     /* +-------  */
        rightX = scalefield->potential[i][j+1];

      } else if (i==0) {                            /* +-------  */
        upY    = scalefield->potential[i+1][j];     /* | |@| |   */
        downY  = scalefield->potential[i+1][j];     /* +-+-+-+   */
        leftX  = scalefield->potential[i][j-1];     /* | | | |   */
        rightX = scalefield->potential[i][j+1];     /*           */

      } else if (i==FIELD_SIZE) {                   /*           */
        upY    = scalefield->potential[i-1][j];     /* | | | |   */
        downY  = scalefield->potential[i-1][j];     /* +-+-+-+   */
        leftX  = scalefield->potential[i][j-1];     /* | |@| |   */
        rightX = scalefield->potential[i][j+1];     /* +-------  */

      } else if (j==0) {                            /* +-+-+-+-  */
        upY    = scalefield->potential[i-1][j];     /* |@| | |   */
        downY  = scalefield->potential[i+1][j];     /* +-+-+-+-  */
        leftX  = scalefield->potential[i][j+1];     /* | | | |   */
        rightX = scalefield->potential[i][j+1];     /* +-+-+-+-  */

      } else if (j==FIELD_SIZE) {                   /* -+-+-+-+  */  
        upY    = scalefield->potential[i-1][j];     /*  | | |@|  */ 
        downY  = scalefield->potential[i+1][j];     /* -+-+-+-+  */ 
        leftX  = scalefield->potential[i][j-1];     /*  | | | |  */
        rightX = scalefield->potential[i][j-1];     /* -+-+-+-+  */

      } else {
        upY    = scalefield->potential[i-1][j];     /* other part */
        downY  = scalefield->potential[i+1][j];
        leftX  = scalefield->potential[i][j-1];
        rightX = scalefield->potential[i][j+1];
      }

   /*  diverge point processing */         
     if (scalefield->potential[i+1][j] == 0.0) 
       downY   = scalefield->potential[i][j]; 
     else if (scalefield->potential[i-1][j] == 0.0) 
       upY     = scalefield->potential[i][j]; 
     else if (scalefield->potential[i][j+1] == 0.0) 
       rightX  = scalefield->potential[i][j]; 
     else if (scalefield->potential[i][j-1] == 0.0) 
       leftX   = scalefield->potential[i][j]; 

     if (scalefield->potential[i][j] == 0.0) {
       vectorfield->pointOf[i][j].x = 0.0;
       vectorfield->pointOf[i][j].y = 0.0;
     } else {   

      vectorfield->pointOf[i][j].x =
             ((leftX - scalefield->potential[i][j] )
            + (scalefield->potential[i][j] - rightX))
            / 2;

      vectorfield->pointOf[i][j].y =
             ((upY - scalefield->potential[i][j])
            + (scalefield->potential[i][j] - downY))
            / 2;
     }
    } /* for 'j' */
  } /* for 'i' */

  return vectorfield;
}
