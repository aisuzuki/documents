/*--------------------------------------
    dot product function 
----------------------------------------*/

#define PI     3.1415

typedef struct component VectorComponent;
typedef struct operator  MessageSelector;
typedef double           quantity;

struct component {

  quantity  x, y, z;
  /* the place where this is now. */
  double    thisX, thisY, thisZ;

};

struct operator {

  quantity          (*dotProduct)(VectorComponent *A, VectorComponent *B);
  VectorComponent  *(*crossProduct)(VectorComponent *A, VectorComponent *B);
  VectorComponent  *(*crossProductWithAngle)(VectorComponent *A, VectorComponent *B,
                                             double theta);
  VectorComponent  *(*newVectorComponent)(void);
  VectorComponent  *(*newUnitVectorComponent)(void);

};

quantity          lambda1(VectorComponent *A, VectorComponent *B);
VectorComponent  *lambda2(VectorComponent *A, VectorComponent *B);
VectorComponent  *lambda3(VectorComponent *A, VectorComponent *B,
                          double theta);
VectorComponent  *lambda4(void);
VectorComponent  *lambda5(void);
MessageSelector  *newMessageSelector(void);
void InitDotproductTest(VectorComponent *A, VectorComponent *B);
void InitCrossproductTest(VectorComponent *A, VectorComponent *B);

/* file ends here */
