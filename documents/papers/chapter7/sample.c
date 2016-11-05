#include <stdio.h>
#include <math.h>

main()
{
    double x, y, t, dt;
    dt = 0.1;

    for (t=0.0; t<1000; t+=dt) {
        x = 1000* exp(t) * (cos(t)+sin(t));
        y = 1000* exp(t) * (cos(t)-sin(t));
        if (y < 1.0 && y > 0.0) 
            fprintf(stderr, "time = %lf", t);

        printf("%lf %lf \n", x, y);
    }
}
