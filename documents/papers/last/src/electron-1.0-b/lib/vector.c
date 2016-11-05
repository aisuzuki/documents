/*	vector.c									    */
/*													*/
/*			Mon, 23 Sep 2002 04:55:44 +0900 		*/
/*			author: ai suzuki<spiral@soulhack.net>	*/

/* code:           */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "field.h"

VectorField *
newVectorField(void)
{
    VectorField  *vfield;
    int           i;

    vfield = (VectorField *)malloc(sizeof (VectorField));
    if (!vfield)
        perror("newVectorField"), exit(EXIT_FAILURE);

    vfield->pointOf = (struct twoDbeing **)malloc(ny * sizeof (struct twoDbeing *));
    for (i = 0; i < ny; i++)
        vfield->pointOf[i] = (struct twoDbeing *)malloc(nx * sizeof (struct twoDbeing));

    return clearVectorField(vfield);
}

VectorField *
clearVectorField(VectorField *vfield)
{
    int  x, y;

    for (y = 0; y < ny; y++) {
        for (x = 0; x < nx; x++) {
            vfield->pointOf[y][x].x = 0.0;
            vfield->pointOf[y][x].y = 0.0;
        }
    }
    return vfield;
}

VectorField *
makeVectorField(ScaleField  *sfield,
                VectorField *vfield)
                
{
    int       x, y;

    for (y = 1; y < ny-1; y++) {
        for (x = 1; x < nx-1; x++) {
            vfield->pointOf[y][x].x = ((sfield->potential[y][x - 1] - sfield->potential[y][x]) / dx
                                    +  (sfield->potential[y][x] - sfield->potential[y][x + 1]) / dx)
                                    / 2.0;
            vfield->pointOf[y][x].y = ((sfield->potential[y - 1][x] - sfield->potential[y][x]) / dy
                                    +  (sfield->potential[y][x] - sfield->potential[y + 1][x]) / dy)
                                    / 2.0;
        } /* for 'x' */
    } /* for 'y' */
    return vfield;
}

/* end of file. */
