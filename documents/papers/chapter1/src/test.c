#include <stdio.h>
#include <math.h>

int main()
{
  double  g, N;
  int     t, dt;
   
  N  = 3.9;
  dt = 1;
  g  = 0.307;

  for (t=0; t<15; t+=dt) {
    printf("%d %f\n", t, g*N*dt+N);
    N = g*N*dt+N;
  }
}
