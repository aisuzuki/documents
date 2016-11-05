/*---------------------------------------
 
   "Matrix" hedder

 ---------------------------------------*/

#define MATRIX_SIZE  60

#define  T    1
#define  NIL  0

typedef struct mat Matrix;

struct mat {

  int  rowsize, columnsize;
  int row[MATRIX_SIZE][MATRIX_SIZE];

};
   
int naiseki(int *VA, int *VB, int size);
int car(int V[]);
int *cdr(int V[]);
Matrix *matmul(Matrix *mat, Matrix *ans, int k);
Matrix *matplus(Matrix *A, Matrix *B, Matrix *ans);
Matrix *mattake(Matrix *A, Matrix *B, Matrix *ans);
Matrix *oppmove(Matrix *mat, Matrix *ans);
Matrix *product(Matrix *A, Matrix *B, Matrix *ans);

/* file ends here */
