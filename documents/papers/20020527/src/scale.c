#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "field.h"

#define   SQUARE(n)  (n*n)

/*  for debug  */
#define   DEBUG 

#ifdef DEBUG 
int main(void)
{
  anElectron   *electrons;
  ScaleField   *scalefield;
  VectorField  *vectorfield;
  int i, j, k;

  scalefield   = newScaleField();
  vectorfield  = newVectorField();
  electrons    = initElectrons(10);  

  scalefield   = buildScaleField(scalefield, electrons, 10);
  vectorfield  = makeVectorField(scalefield, vectorfield);

/*
   for (i=0; i<FIELD_SIZE; i++) {
    for (j=0; j<FIELD_SIZE; j++) {
      printf("%d %d %10f \n",i, j, scalefield->potential[i][j]);
    }
    printf("\n");
  }

*/
   for (i=0; i<FIELD_SIZE; i++) {
     if ((i-1) < 0)
      continue;
      else if (i == FIELD_SIZE-1)
      break;

     for (j=0; j<FIELD_SIZE; j++) {
       if ((j-1) < 0)
        continue;
       else if (j == FIELD_SIZE-1)
        break;

       printf("%d %d %10f %10f\n", i, j, 
         vectorfield->pointOf[i][j].x, vectorfield->pointOf[i][j].y);
     }
     printf("\n");
   }

  return 0;
}
#endif


ScaleField *makeScaleField(ScaleField *scalefield, anElectron electrons)
{
  double dx, dy;
  int i, j, k, l, inck, incl, halfsizeX, halfsizeY;
  
  dx = 1.0;
  dy = 1.0;
  
  halfsizeX = (FIELD_SIZE / 2) + (int)(electrons.x);
  halfsizeY = (FIELD_SIZE / 2) - (int)(electrons.y); 
    
  for (i=0, k=halfsizeY, inck=1; i<FIELD_SIZE; i++, k-=inck) {
    for (j=0, l=halfsizeX, incl=1; j<FIELD_SIZE; j++, l-=incl) {

      scalefield->potential[i][j] += (electrons.q 
                                   / (sqrt(SQUARE(l+dx) + SQUARE(k+dy))));
      if(l==0)
       incl *= -1;
    } /* for 'j' */
    if(k==0)
     inck *= -1;
  } /* for 'i' */

  return scalefield;
}

ScaleField  *buildScaleField(ScaleField  *scalefield, 
                             anElectron   electrons[], int number)
{
  int i;
  
  for (i=0; i<number; i++)
    scalefield = makeScaleField(scalefield, electrons[i]);
 
  return scalefield;
}

VectorField *makeVectorField(ScaleField  *scalefield, 
                             VectorField *vectorfield)
{
  int  i, j, dx, dy;

  dx = 1.0;
  dy = 1.0;

  for (i=0; i<FIELD_SIZE; i++) {
    if ((i-1) < 0) 
      continue;
    else if (i == FIELD_SIZE-1) 
      break;
    
    for (j=0; j<FIELD_SIZE; j++) {
      if ((j-1) < 0) 
       continue;
      else if (j == FIELD_SIZE-1) 
      break;
    
    vectorfield->pointOf[i][j].x = 
             (((scalefield->potential[i][j-1] - scalefield->potential[i][j])   / dx)
            + ((scalefield->potential[i][j]   - scalefield->potential[i][j+1]) / dx))
            / 2;

    vectorfield->pointOf[i][j].y = 
             (((scalefield->potential[i-1][j] - scalefield->potential[i][j])   / dy)
            + ((scalefield->potential[i][j]   - scalefield->potential[i+1][j]) / dy))
            / 2;

    } /* for 'j' */
  } /* for 'i' */

  return vectorfield;
}

anElectron *initElectrons(int n)
{
  anElectron *electrons;
  int i;
  
  electrons = (anElectron *)calloc(n, sizeof(anElectron));  
  srand(time(0)); 

  for (i=0; i<n; i++) {
    electrons[i].q  =   30.0*RAND-15.0;
    electrons[i].x  = ((double)FIELD_SIZE) * RAND - ((double)FIELD_SIZE) / 2.0;
    electrons[i].y  = ((double)FIELD_SIZE) * RAND - ((double)FIELD_SIZE) / 2.0;
    electrons[i].vx = 1.0;
    electrons[i].vy = 1.0;

  }
  return electrons;
}

ScaleField *newScaleField(void)
{
  ScaleField  *scalefield;
  int i, j;
  
  scalefield = (ScaleField *)malloc(sizeof (ScaleField));

  for (i=0; i<FIELD_SIZE; i++)
    for (j=0; j<FIELD_SIZE; j++)
      scalefield->potential[i][j] = 0.0; 
  
  return scalefield;
}

VectorField *newVectorField(void)
{
  VectorField  *vectorfield;
  int i, j;
  
  vectorfield = (VectorField *)malloc(sizeof (VectorField));

  for (i=0; i<FIELD_SIZE; i++) {
    for (j=0; j<FIELD_SIZE; j++) {
      vectorfield->pointOf[i][j].x = 0.0; 
      vectorfield->pointOf[i][j].y = 0.0; 
    } 
  }
  return vectorfield;
}

void initWorld(void)
{
  printf("set xrange [%d:%d]\n", -(FIELD_SIZE/2), (FIELD_SIZE/2));
  printf("set yrange [%d:%d]\n", -(FIELD_SIZE/2), (FIELD_SIZE/2));
/*  printf("set size square\n"); */
  printf("set format x \"\" \n"); 
  printf("set format y \"\" \n"); 
}
