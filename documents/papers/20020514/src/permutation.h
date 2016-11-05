/*---------------------------------------

   "permutation" hedder

 ---------------------------------------*/

/* for debug */
#define TRACE 

#define  PERMUTATION_SIZE  64
#define  ROW                2
#define  UPPER              0
#define  LOWER              1

#define  EVEN    1
#define  ODD    -1 

typedef struct expresson Permutation;

struct expresson {

  int  expressonSize;
  int  row[ROW][PERMUTATION_SIZE];

};
   
int           sign(Permutation *exp);
Permutation  *swap(Permutation *exp, int from, int to);
Permutation  *init(Permutation *exp, int size);

/* file ends here */
