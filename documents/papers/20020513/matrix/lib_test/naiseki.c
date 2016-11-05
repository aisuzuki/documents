#include <stdio.h>
#include "matrix.h"

int naiseki(int *VA, int *VB, int size)
{
    int answer;
    int i;
    answer = 0;
   
    for (i=0; i<size; i++) { 
      answer += car(VA+i) * car(VB+i);
    }
    return answer;
}

/* file ends here */
