/* scale.c                                  */
/*                                          */
/*      Wed, 25 Sep 2002 00:49:00 +0900     */
/*   author: ai suzuki<spiral@soulhack.net> */

/* code:           */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "field.h"

#define  SQUARE(n) ((n)*(n)) 

ScaleField *
makeScaleField(ScaleField *sfield, 
               anElectron      *e)
{
    anElectron  *etmp;
    int          x, y;

    for (y = 0; y < ny; y++) {
        for (x = 0; x < nx; x++) {

            sfield->potential[y][x] = 0.0;
            for (etmp = e; etmp != NULL; etmp = etmp->next) {

                double  distanceX, distanceY;
                double  thisX, thisY;
                int     tmpX, tmpY;

                /*  make index. */
                tmpX  = (int)(etmp->x / dx);
                tmpY  = (int)(etmp->y / dy);
                
                if ((tmpX == x) && (tmpY == y)) {
                    sfield->potential[y][x] = (double)FIXED_SCALE_VALUABLE * etmp->q;
                } else {
                    thisX = ((tmpX * dx) + (dx * 0.5));
                    thisY = ((tmpY * dy) + (dy * 0.5));

                    distanceX = thisX - ((x * dx) + (dx * 0.5));
                    distanceY = thisY - ((y * dy) + (dy * 0.5));
                    sfield->potential[y][x] += ((etmp->q * etmp->m)
                                            / sqrt(SQUARE(distanceX) + SQUARE(distanceY)));
                }
            }
        } /* for 'x' */
    } /* for 'y' */
    return sfield;
}

ScaleField *
clearScaleField(ScaleField *sfield)
{
    int     x, y;
    
    for (y = 0; y < ny; y++)
        for (x = 0; x < nx; x++)
            sfield->potential[y][x] = 0.0;

    return sfield;
}

ScaleField *
newScaleField(void)
{
    ScaleField  *sfield;
    int               i;

    sfield = (ScaleField *)malloc(sizeof(ScaleField));
    if (!sfield)
        perror("newScalefield"), exit(EXIT_FAILURE);

    sfield->potential = (double **)malloc(sizeof(double *) * ny);
    for (i = 0; i < ny; i++)
        sfield->potential[i] = (double *)malloc(sizeof(double) * nx);

    return  clearScaleField(sfield);
}

/* file ends here. */
