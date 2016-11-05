#include <stdio.h>
#include "permutation.h"

int main(void)
{
  Permutation  permutation;
  Permutation *sigma;
  int          answer;

  sigma = &permutation; 
  sigma = init(sigma, 5);

  answer = sign(sigma);
  
  (answer == EVEN) ? printf("permutation changes EVEN times to constant permutation.\n")
                   : printf("permutation changes ODD  times to constant permutation.\n"); 
  return 0;                 
}
