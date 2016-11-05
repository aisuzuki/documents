#include <stdio.h>
#include <math.h>
#include "field.h"

#define ABS(n)  ((n < 0) ?  -1*n : n)

#define  N   10
#define  K  4.0

int main(void)
{
  anElectron   *electrons;
  ScaleField   *scalefield;
  VectorField  *vectorfield;

  double  dx, dy, dvx, dvy, dt, ax, ay, fx, fy;
  double  xmin, xmax, ymin, ymax;
  int i, j, number, thisX, thisY;
  int ti;
  
  xmin = ymin = -(FIELD_SIZE/2); 
  xmax = ymax =  (FIELD_SIZE/2); 

  vectorfield = newVectorField();

  number      = 2; 
  electrons   = initElectrons(number); 
  
  dt = 0.1;
  initWorld();

  for (ti=0; ; ti++) {
  
    for (i=0; i<number; i++) {
      fx = 0.0;
      fy = 0.0;
      scalefield  = newScaleField();
      
      if (electrons[i].q < 0)  
        printf("plot \"-\" w p 1 3\n");  
      else 
        printf("plot \"-\" w p 5 1\n");  

      for (j=0; j<number; j++) {  
        if (j == i) continue;
        scalefield  = makeScaleField(scalefield, electrons[j]);
      }

      thisX = (FIELD_SIZE/2) + (int)(electrons[i].x); 
      thisY = (FIELD_SIZE/2) - (int)(electrons[i].y); 
      vectorfield = makeVectorField(scalefield, vectorfield);
      fx = vectorfield->pointOf[thisY][thisX].x * electrons[i].q; 
      fy = vectorfield->pointOf[thisY][thisX].y * electrons[i].q; 
         
      ax = fx / ABS(electrons[i].q);
      ay = fy / ABS(electrons[i].q);

      dvx = ax * dt;
      dvy = ay * dt;
      
      electrons[i].vx = electrons[i].vx + dvx;
      electrons[i].vy = electrons[i].vy + dvy;


   /*   warp to ..       
      if (electrons[i].x < xmin)
        electrons[i].x = xmax;
      else if (electrons[i].x > xmax) 
        electrons[i].x = xmin;
        
      if (electrons[i].y < ymin)
        electrons[i].y = ymax;
      else if (electrons[i].y > ymax) 
        electrons[i].y = ymin;
   */ 
  
   /*   bound to ..   */ 

      if ((electrons[i].x < xmin) || (electrons[i].x > xmax))
        electrons[i].vx *= -1;
        
      if ((electrons[i].y < ymin) || (electrons[i].y > ymax))
        electrons[i].vy *= -1;
   

      dx = electrons[i].vx * dt;
      dy = electrons[i].vy * dt;

      electrons[i].x = electrons[i].x + dx; 
      electrons[i].y = electrons[i].y + dy; 

      /* É½¼¨ */
      printf("%f  %f\n",electrons[i].x, electrons[i].y);
     /* free(scalefield); */

      printf("e\n");
      }
   }     
   return 0;
}
