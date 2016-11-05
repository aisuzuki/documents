/*----------------------------------------
    field for electron 
 -----------------------------------------*/

#define   FIELD_SIZE  100

#define   RAND ((double) rand()/(double)RAND_MAX)

typedef struct sfield    ScaleField;
typedef struct vfield    VectorField;
typedef struct electron  anElectron;

/*---------- electron exists ----------------*/
struct electron {
  double q;
  double x, y;
  double vx, vy;
};
/*-------------------------------------------*/

/*---------- scale field --------------------*/
struct sfield {
   double  potential[FIELD_SIZE][FIELD_SIZE];
};
/*-------------------------------------------*/

/*---------- vector field -------------------*/
struct point {
   double  x, y;
};

struct vfield {
   struct point pointOf[FIELD_SIZE][FIELD_SIZE];
};
/*-------------------------------------------*/

anElectron  *initElectrons(int n);
ScaleField  *newScaleField(void);
VectorField *newVectorField(void);
ScaleField  *makeScaleField(ScaleField  *scalefield, anElectron  electrons);
ScaleField  *buildScaleField(ScaleField  *scalefield, anElectron  electrons[], int number);
VectorField *makeVectorField(ScaleField *scalefield, VectorField *vectorfiled);
void initWorld(void);
