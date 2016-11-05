#include <stdio.h>
#include <math.h>
#include "../field.h"

#define SQUARE(n)   (n*n)

int main(void)
{ 
  ScaleField field;
  double dx, dy;
  int i, j, k, l, inck, incl, halfsize;
  
  if ((FIELD_SIZE % 2) == 0)
    halfsize = (FIELD_SIZE / 2);  
  else 
    halfsize = (FIELD_SIZE / 2)+1;  

  dx     = 1.0;
  dy     = 1.0;
     
  for (i=0, k=halfsize, inck=1; i<FIELD_SIZE; i++, k-=inck) { 
    for (j=0, l=halfsize, incl=1; j<FIELD_SIZE; j++, l-=incl) { 
      field.potential[i][j] = 1/ (sqrt(SQUARE((k+dx)/2) + SQUARE((l+dy)/2)));
                              
      if(l==0)
       incl *= -1;
    }
    if(k==0)
    inck *= -1;
  }

  for (i=0; i<FIELD_SIZE; i++) {
    for (j=0; j<FIELD_SIZE; j++) {
      printf("%d %d %10f \n",i, j, field.potential[i][j]);
    }
    printf("\n");
  }
  return 0;
}
