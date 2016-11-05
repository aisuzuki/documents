/* field.h                                  */
/*                                          */
/*      Fri, 27 Sep 2002 03:04:06 +0900     */
/*   author: ai suzuki<spiral@soulhack.net> */

/* code:           */

/*-------------------------------------------------
  electron
---------------------------------------------------*/

#define   RAND ((double) rand()/(double)RAND_MAX)

typedef struct electron  anElectron;
typedef struct sfield    ScaleField; 
typedef struct vfield   VectorField; 

/* literal valuables*/
enum literal {
    FIELD_SIZE           = 50,    /* size of field */
    FIXED_SCALE_VALUABLE = 50,    /* current scale valuable. at 'scale.c' */
    VECTOR_LENGTH        = 2,     /* say no more. */
    I_O                  = 2,     /* input or output files */ 
    INPUT_FILE           = 0,     /* index of input file name */ 
    OUTPUT_FILE          = 1,     /* index of output file name */ 
    FILE_NAME_SIZE       = 128,   /* file name array size */ 
    BUF_SIZE             = 1024,  /* general buffer array size */ 
    FLAG                 = 4      /* option flag */ 
};

/* how electrons are these created */
/* random or defaluts              */
enum on_off {
    OFF,
    ON
};

enum option_flag {
    IF,
    OF,
    BN,
    FN
};

unsigned int flag[FLAG];
unsigned int random_flag;

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
    int      m;
    double   x, y;
    double   vx, vy;
    struct electron *next;
};
/*-----------------------------------------------*/

/*----------- Global Valuable -------------------*/

int     nx, ny;  /* orderd division   */
double  dx, dy;  /* differ from neighboring 'x's and 'y's. */
int          t;  /* time              */
double      dt;  /* time differ       */
int         bn;  /* individual number */ 
int         fn;  /* output flame size */ 

char filename[I_O][FILE_NAME_SIZE];

/*-----------------------------------------------*/

/* proc_opt.c */
void procOptions(int argc, char *argv[]);

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
void  outputScaleDataFormat(ScaleField *sfield);

/* inspect.c */
void inspectIt(anElectron *e);

/* file.c */
void outputFile(anElectron *e);

/* world.c */
anElectron  *initElectrons(void);
void         theWorld(void);

/* file ends here. */
