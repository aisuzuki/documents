#include <stdio.h>
#include <math.h>
#include "field.h"

#define  ABS(n)  ((n<0) ? -1*n : n)

int main(void)
{
  anElectron   elect[2], *electrons;
  ScaleField  *scalefield; 
  VectorField *vectorfield;

  double dx, dy, dvx, dvy, dt, ax, ay, fx, fy;
  double xmin, xmax, ymin, ymax;
  int i, j, l, k, ti, number, thisX, thisY;
 
  xmin = ymin = -(FIELD_SIZE/2);
  xmax = ymax =  (FIELD_SIZE/2);
 
  vectorfield = newVectorField();
  scalefield  = newScaleField();
  number      = 5;

  electrons   = initElectrons(number, "hoge", "hoge");
 /* test  */
  electrons   = elect;
  electrons[0].q  = -20.0;
  electrons[0].x  =  5.0;
  electrons[0].y  =  8.0;
  electrons[0].vx =  0.0;
  electrons[0].vy =  0.0;

  electrons[1].q  = 20.0;
  electrons[1].x  = -3.0;
  electrons[1].y  =  5.0;
  electrons[1].vx =  0.0;
  electrons[1].vy =  0.0;


  dt = 0.1;
  initWorld();

  for (ti=0; ; ti++) {
    printf("plot \"-\" w p\n");
    for (i=0; i<number; i++) { 

      fx = 0.0;
      fy = 0.0;

      scalefield  = clearScaleField(scalefield);

      for (j=0; j<number; j++) { 
        if (i==j) 
          continue;
        scalefield = makeScaleField(scalefield, electrons[j]);
      }/* for 'j' */

      vectorfield = makeVectorField(scalefield, vectorfield);

      thisX = (FIELD_SIZE / 2) + (int)(electrons[i].x);
      thisY = (FIELD_SIZE / 2) - (int)(electrons[i].y);
     
      fx = electrons[i].q * vectorfield->pointOf[thisY][thisX].x; 
      fy = electrons[i].q * vectorfield->pointOf[thisY][thisX].y; 

      ax  = fx / ABS(electrons[i].q);
      ay  = fy / ABS(electrons[i].q);
      
      dvx = ax * dt;
      dvy = ay * dt;
      
      electrons[i].vx += dvx;
      electrons[i].vy += dvy;

   /*   bound to ..  */

      if (electrons[i].x < xmin) {
        electrons[i].vx *= -1;
        electrons[i].x   = xmin;
      } else if (electrons[i].x > xmax) {
        electrons[i].vx *= -1;
        electrons[i].x   = xmax;
      } 
      if (electrons[i].y < xmin) {
        electrons[i].vy *= -1;
        electrons[i].y   = ymin;
      } else if (electrons[i].y > ymax) {
        electrons[i].vy *= -1;
        electrons[i].y   = ymax;
      }

      dx = electrons[i].vx * dt;
      dy = electrons[i].vy * dt;
       
      electrons[i].x += dx;
      electrons[i].y += dy;
      
      
      printf("%f %f\n", electrons[i].x, electrons[i].y);
      fflush(stdout);

    }/* for 'i' */
    printf("e\n");
  }/* for 'ti' */

 return 0;
} 
