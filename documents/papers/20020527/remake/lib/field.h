/*-------------------------------------------------
  electron
---------------------------------------------------*/

#define FIELD_SIZE    25

#define   RAND ((double) rand()/(double)RAND_MAX)

typedef struct electron  anElectron;
typedef struct sfield    ScaleField; 
typedef struct vfield   VectorField; 

/*-------------- 2D being -----------------------*/
struct twoDbeing {
  double x, y;
};
/*-----------------------------------------------*/

/*------------- vector field --------------------*/
struct vfield {
  struct twoDbeing pointOf[FIELD_SIZE][FIELD_SIZE]; 
};
/*-----------------------------------------------*/

/*------------ scale field ----------------------*/
struct sfield {
  double  potential[FIELD_SIZE][FIELD_SIZE];
};
/*-----------------------------------------------*/

/*----------- an Electron -----------------------*/
struct electron {
  double q;
  double x, y;
  double vx, vy;
};
/*-----------------------------------------------*/

ScaleField  *newScaleField(void);
ScaleField  *clearScaleField(ScaleField *scalefield);
ScaleField  *makeScaleField(ScaleField *scalefield, anElectron electrons);
VectorField *newVectorField(void);
VectorField *makeVectorField(ScaleField  *scalefield, VectorField *vectorfield);
void initWorld(void);
anElectron *initElectrons(int n);
void theWorld(int number);
