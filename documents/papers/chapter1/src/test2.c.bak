#include <stdio.h>
#include <math.h>

int main()
{
  double  g, N, N_inf;
  int     t, dt;
   
  N     = 3.9;
  N_inf = 197;
  dt    = 1;
  g     = 0.3134;

  for (t=0; t<12; t+=dt) {
    printf("%d %f\n", t, g*N*dt*(1-(N/N_inf))+N*(1-(N/N_inf)));
    N = g*N*dt*(1-(N/N_inf))+N*(1-(N/N_inf));
  }
}
