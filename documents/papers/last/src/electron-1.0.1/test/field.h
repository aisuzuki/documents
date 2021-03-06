/*	field.h     									*/
/*													*/
/*			Mon, 23 Sep 2002 05:13:24 +0900  		*/
/*			author: ai suzuki<spiral@soulhack.net>	*/

/* code:           */

/*-------------------------------------------------
  electron
---------------------------------------------------*/

#define   RAND ((double) rand()/(double)RAND_MAX)

typedef struct electron  anElectron;
typedef struct sfield    ScaleField; 
typedef struct vfield   VectorField; 

/* literal valuables*/
enum {
    FIELD_SIZE           = 50,    /* size of field */
    FIXED_SCALE_VALUABLE = 100,   /* current scale valuable. at 'scale.c' */
    VECTOR_LENGTH        = 2      /* say no more. */
};

/*-------------- 2D being -----------------------*/
struct twoDbeing {
    double  x, y;
};
/*-----------------------------------------------*/

/*------------- vector field --------------------*/
struct vfield {
    struct  twoDbeing **pointOf; 
};
/*-----------------------------------------------*/

/*------------ scale field ----------------------*/
struct sfield {
    double  **potential;
};
/*-----------------------------------------------*/

/*----------- an Electron -----------------------*/
struct electron {
    double   q;
    double   x, y;
    double   vx, vy;
    struct electron *next;
};
/*-----------------------------------------------*/

/*----------- Global Valuable -------------------*/

int     nx, ny;  /* orderd division   */
double  dx, dy;  /* differ from neighboring 'x's and 'y's. */
double   t, dt;  /* time valuable     */
int         bn;  /* individual number */ 

/*-----------------------------------------------*/

/* scale.c */
ScaleField  *newScaleField(void);
ScaleField  *makeScaleField(ScaleField *sfield, anElectron *e);
ScaleField  *clearScaleField(ScaleField *sfield);

/* vector.c */
VectorField *newVectorField(void);
VectorField *makeVectorField(ScaleField  *sfield, VectorField *vfield);
VectorField  *clearVectorField(VectorField *vfield);

/* plot.c */
void  initWorld(void);
void  outputVectorDataFormat(VectorField *vfield);

/* inspect.c */
void inspectIt(anElectron *e);

/* world.c */
anElectron  *initElectrons(int n, char *mode, char *modeArg);
void         theWorld(char *mode, char *modeArg);

/* file ends here. */
