#include <stdio.h>
#include "field.h"

void initWorld(void)
{
  printf("set xrange [%d:%d]\n",-(FIELD_SIZE/2), (FIELD_SIZE/2));
  printf("set yrange [%d:%d]\n",-(FIELD_SIZE/2), (FIELD_SIZE/2));
  printf("set size square\n");  
  printf("set format x \"\" \n");
  printf("set format y \"\" \n"); 
}

