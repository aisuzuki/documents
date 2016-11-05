/* world.c                                  */
/*                                          */
/*      Fri, 27 Sep 2002 03:05:02 +0900     */
/*   author: ai suzuki<spiral@soulhack.net> */

/* code:           */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "field.h"
#include "file.h"

#define  SQARE(n) (n*n)

anElectron *
initElectrons()
{
    anElectron  *etmp, *e;
    int i;

    if (bn > 0) {

        e = (anElectron *)malloc(sizeof(anElectron));
        etmp = e;
        bn--;
        for (i = 0; i < bn; i++) {
            etmp->next = (anElectron *)malloc(sizeof(anElectron));
            etmp = etmp->next;
        }
        etmp = NULL;

        if (flag[IF]) {
           loadFromFile(e);
        
        } else {

            srand(time(0));
            for (etmp = e; etmp != NULL; etmp = etmp->next) {
                etmp->m  = 20.0*RAND;
                etmp->q  = ((2.0*RAND-1.0) > 0) ? -1.0 : 1.0;
                etmp->x  = ((double)FIELD_SIZE) * RAND; 
                etmp->y  = ((double)FIELD_SIZE) * RAND; 
                etmp->vx = 0.0;
                etmp->vy = 0.0;
                inspectIt(etmp);
            }
        }
        return e;
    } else {
    /* zero electron. */
    return NULL;
    }
}

void 
theWorld()
{
    anElectron  *e, *etmp;
    ScaleField    *sfield;
    VectorField   *vfield;

    double       ldx, ldy;  /* local dx, dy. */
    double       dvx, dvy;
    double        ax,  ay;
    double        fx,  fy;
    double     xmin, xmax;
    double     ymin, ymax;
    double             ti;
    int                fi;
    int    indexX, indexY;

    fi   = 0;
    xmin = ymin = 0.0;
    xmax = ymax = FIELD_SIZE;

    initWorld();

    /* field initialize. */
    vfield = newVectorField();
    sfield = newScaleField();
    e      = initElectrons();

    for (ti=0.0; ti < t; ti += dt) {
        
        sfield = makeScaleField(sfield, e);
        makeVectorField(sfield, vfield);

/*#ifdef VECTOR*/
/*            printf("plot [%f:%f][%f:%f] \"-\" w vector\n", 0.0, (double)FIELD_SIZE,*/
/*                                                           0.0, (double)FIELD_SIZE);*/
/*#endif*/
/*#ifdef SCALE*/
/*            printf("splot [%f:%f][%f:%f] \"-\" w l\n", 0.0, (double)FIELD_SIZE,*/
/*                                                       0.0, (double)FIELD_SIZE);*/
/*#endif*/

        printf("plot [%f:%f][%f:%f] \"-\" w p\n", 0.0, (double)FIELD_SIZE,
                                                      0.0, (double)FIELD_SIZE);

        for (etmp = e; etmp != NULL; etmp = etmp->next) {

            fx = 0.0;
            fy = 0.0;
            indexX = (int)(etmp->x / dx);
            indexY = (int)(etmp->y / dy);
            assert(!(indexX > nx) && !(indexY > ny));

            fx = etmp->q * vfield->pointOf[indexY][indexX].x;
            fy = etmp->q * vfield->pointOf[indexY][indexX].y;

            ax  = fx / etmp->m;
            ay  = fy / etmp->m;

            dvx = ax * dt;
            dvy = ay * dt;

            etmp->vx += dvx;
            etmp->vy += dvy;

            ldx = etmp->vx * dt;
            ldy = etmp->vy * dt;
            etmp->x += ldx;
            etmp->y += ldy;

            if (etmp->x < xmin) {
                etmp->vx *= -1.0;
                etmp->x   = xmin + 1.0;
            } else if (etmp->x > xmax) {
                etmp->vx *= -1.0;
                etmp->x   = xmax - 1.0;
            } 
            if (etmp->y < ymin) {
                etmp->vy *= -1.0;
                etmp->y   = ymin + 1.0;
            } else if (etmp->y > ymax) {
                etmp->vy *= -1.0;
                etmp->y   = ymax - 1.0;
            }

/*#ifdef VECTOR*/
/*  output vector data format.  */
/*            outputVectorDataFormat(vfield); */
/*#endif*/
/*  output vector data format.  */
/*            outputScaleDataFormat(sfield); */

            /* defalut */
            printf("%f %f\n", etmp->x, etmp->y);

            if ((fn != 0) && (fi < fn)) {
                fprintf(stderr, "%f %f", etmp->x, etmp->y);
            }

        } /* for 'e' */
        printf("e\n");
        fflush(stdout);

    }/* for 'ti' */

    /* if option '--of' was ordered,              */
    /* output latest status of electrons to file. */

    if (flag[OF]) {
        outputFile(e);
    }
}

/* file ends here. */
