/* inspect.c                                */
/*                                          */
/*      Wed, 25 Sep 2002 22:07:20 +0900     */
/*   author: ai suzuki<spiral@soulhack.net> */

/* code:           */
#include <stdio.h>
#include "field.h"

void
inspectIt(anElectron *e)
{
    fprintf(stderr, "-----------------------\n");
    fprintf(stderr, "q  = \t%f              \n"
                    "m  = \t%d              \n"
                    "x  = \t%f              \n"
                    "y  = \t%f              \n"
                    "vx = \t%f              \n"
                    "vy = \t%f              \n", e->q,  e->m,
                                                 e->x,  e->y, 
                                                 e->vx, e->vy);
    fprintf(stderr, "-------------------------\n");
}

/* file ends here. */
