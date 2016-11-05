/*	plot.c      									*/
/*													*/
/*			Mon, 23 Sep 2002 05:11:48 +0900 		*/
/*			author: ai suzuki<spiral@soulhack.net>	*/

/* code:           */

#include <stdio.h>
#include <math.h>

#include "field.h"

#define SQUARE(n) ((n) * (n))

void 
initWorld(void)
{
    printf("set contour\n");
/*    printf("set xrange [%d:%d]\n", 0, FIELD_SIZE);*/
/*    printf("set yrange [%d:%d]\n", 0, FIELD_SIZE);*/
/*    printf("set size square\n");  */
/*    printf("set format x \"\" \n");*/
/*    printf("set format y \"\" \n"); */
}

void
outputVectorDataFormat(VectorField *vfield)
{
   int      x, y;
   double      r;
    
    for (y=0; y<ny; y++) {  
        for (x=0; x<nx; x++) {  
            r = sqrt(SQUARE(vfield->pointOf[y][x].x) + SQUARE(vfield->pointOf[y][x].y));
                if (r == 0.0) {
                    printf("%f %f %f %f\n", (double)x * dx + (dx * 0.5), 
                                            (double)y * dy + (dy * 0.5), 0.0, 0.0);
                } else {
                    printf("%f %f %f %f\n", (double)x * dx + (dx * 0.5), 
                                            (double)y * dy + (dy * 0.5), 
                                            (double)VECTOR_LENGTH * vfield->pointOf[y][x].x / r, 
                                            (double)VECTOR_LENGTH * vfield->pointOf[y][x].y / r);
                }
        } /* for 'x' */
            printf("\n");
    } /* for 'y' */
}

void
outputScaleDataFormat(ScaleField *sfield)
{
    int     x, y;

    for (y=0; y<ny; y++) { 
        for (x=0; x<nx; x++) { 
            printf("%f %f %f\n", (double)x * dx + (dx * 0.5)
                               , (double)y * dy + (dy * 0.5), sfield->potential[y][x]);
        }
        printf("\n");
    }
}

/* file ends here. */
