#include <stdio.h>
#include <math.h>

#define TEKITO(n) (n*n*n)

main()
{
    double x, A;
    A = 2.0;

    for (x=0.0; x<1000; x++) {
        printf("%lf %lf \n", x, (1.0/3.0)*sqrt(TEKITO(2.0*x+2.0*A)));
    }
}
