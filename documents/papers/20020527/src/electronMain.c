#include <stdio.h>
#include <math.h>
#include "field.h"

#define  N   10
#define  K  4.0

int main(void)
{
  anElectron   elect[2], *electrons;
  ScaleField   *scalefield;
  VectorField  *vectorfield;

  double  dx, dy, dvx, dvy, dt, ax, ay, fx, fy;
  double  xmin, xmax, ymin, ymax;
  int i, j, k, l,  number, thisX, thisY;
  int ti;
  
  xmin = ymin = -(FIELD_SIZE/2); 
  xmax = ymax =  (FIELD_SIZE/2); 

  vectorfield = newVectorField();

  number      = 5; 
/*  electrons = elect;
  electrons[0].q = -1.0;
  electrons[0].x = 5.0;
  electrons[0].y = 0.0;
  electrons[0].vx = 0.0;
  electrons[0].vy = 0.0;

  electrons[1].q = 1.0;
  electrons[1].x = -5.0;
  electrons[1].y = 0.0;
  electrons[1].vx = 0.0;
  electrons[1].vy = 0.0; */

 electrons   = initElectrons(number); 
  
  dt = 0.1;
  initWorld();

/* config for tex   
  i = 0;
  printf("set term postscript eps enhanced\n"); */

  for (ti=0; ; ti++) {

    printf("splot \"-\" w l \n");  
/*    
    if ((ti % 10) == 0) {
    printf("set output \"2elec%d.eps\"\n",ti);
    printf("plot \"-\"\n");  
    } */

    for (i=0; i<number; i++) {
      fx = 0.0;
      fy = 0.0;
      scalefield  = newScaleField();

      for (j=0; j<number; j++) {  
        if (j == i) continue;
        scalefield  = makeScaleField(scalefield, electrons[j]);
      }
      
      thisX = (FIELD_SIZE/2) + (int)(electrons[i].x);
      thisY = (FIELD_SIZE/2) - (int)(electrons[i].y);

      vectorfield = makeVectorField(scalefield, vectorfield);
      fx = vectorfield->pointOf[thisY][thisX].x * electrons[i].q; 
      fy = vectorfield->pointOf[thisY][thisX].y * electrons[i].q; 
      for (l=0; l<FIELD_SIZE; l++) {
         for (k=0; k<FIELD_SIZE; k++) {
        printf("%d %d %7lf\n", l, k, scalefield->potential[l][k]);
         }
      }  
      printf("\n");
      ax = -fx / electrons[i].q;
      ay = -fy / electrons[i].q;

      dvx = ax * dt;
      dvy = ay * dt;
      
      electrons[i].vx = electrons[i].vx + dvx;
      electrons[i].vy = electrons[i].vy + dvy;


   /*   warp to ..        */ 
      if (electrons[i].x < xmin)
        electrons[i].x = xmax;
      else if (electrons[i].x > xmax) 
        electrons[i].x = xmin;
        
      if (electrons[i].y < ymin)
        electrons[i].y = ymax;
      else if (electrons[i].y > ymax) 
        electrons[i].y = ymin;
  
  
   /*   bound to ..   

      if ((electrons[i].x < xmin) || (electrons[i].x > xmax))
        electrons[i].vx *= -1;
        
      if ((electrons[i].y < ymin) || (electrons[i].y > ymax))
        electrons[i].vy *= -1;
   
*/ 
      dx = electrons[i].vx * dt;
      dy = electrons[i].vy * dt;

      electrons[i].x = electrons[i].x + dx; 
      electrons[i].y = electrons[i].y + dy; 

      /* É½¼¨ */
/*    if ((ti % 2) == 0)  */
/*      printf("%f  %f  %lf %lf \n",electrons[i].x, electrons[i].y, electrons[i].vx, electrons[i].vy);  */
      free(scalefield); 
   }
/*    if ((ti % 2) == 0)  */
      printf("e\n");

   }     
   return 0;
}
