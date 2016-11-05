/*---------------------------------------
 
   "Matrix" hedder

 ---------------------------------------*/

#define MATRIX_SIZE  60

#define  T    1
#define  NIL  0

typedef struct mat Matrix;
typedef struct matrix_operator MatrixOperator;

struct mat {

  int  rowsize, columnsize;
  int row[MATRIX_SIZE][MATRIX_SIZE];

};

struct matrix_operator {
  /* method */
  Matrix *(*matmul)(Matrix *mat, Matrix *ans, int k);
  Matrix *(*matplus)(Matrix *A, Matrix *B, Matrix *ans);
  Matrix *(*mattake)(Matrix *A, Matrix *B, Matrix *ans);
  Matrix *(*oppmove)(Matrix *mat, Matrix *ans);
  Matrix *(*product)(Matrix *A, Matrix *B, Matrix *ans);
};
   
int naiseki(int *VA, int *VB, int size);
int car(int V[]);
int *cdr(int V[]);
Matrix *lambda1(Matrix *mat, Matrix *ans, int k);
Matrix *lambda2(Matrix *A, Matrix *B, Matrix *ans);
Matrix *lambda3(Matrix *A, Matrix *B, Matrix *ans);
Matrix *lambda4(Matrix *mat, Matrix *ans);
Matrix *lambda5(Matrix *A, Matrix *B, Matrix *ans);

/* file ends here */
