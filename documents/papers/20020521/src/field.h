/*-------------------------------------------
    field 
 --------------------------------------------*/

#define FIELD_SIZE    10

typedef struct sfield    ScaleField;
typedef struct vfield    VectorField;
typedef struct cultivate FieldMaker; 

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

/*--------- cultivate the fields! ------------*/
struct cultivate {
   ScaleField  *(*makeScaleField)(ScaleField *field);
   VectorField *(*makeVectorField)(ScaleField *scalefield);
};
/*-------------------------------------------*/

ScaleField *lambda1(ScaleField *field);
VectorField *lambda2(ScaleField *scalefield);
FieldMaker *newFieldMaker(void);

/* file ends here */
