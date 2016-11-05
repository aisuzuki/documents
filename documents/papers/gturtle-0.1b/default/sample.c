#include <stdio.h>
#include <math.h>

#define UP    0
#define DOWN  1

char command[128][128];
char parameter[128][128];
char commandNumber;

void gturtleInit(void);
void gturtleGetCommand(void);
void gturtleDraw(void);
void fd(double len);
void rt(double th);
void penUp(void);
void penDown(void);
void init(void);
void line(double x1, double y1, double x2, double y2);
void quit(void);

int
main(void)
{
    gturtleInit();
    while (1) {
        gturtleGetCommand();
        gturtleDraw();
    }
}

void
gturtleInit(void)
{
    commandNumber = 0;
    strcpy(command[ commandNumber++ ],   "init");
    strcpy(command[ commandNumber++ ],   "pd"  );
    strcpy(command[ commandNumber   ],   "fd"  );
    strcpy(parameter[ commandNumber++ ], "1.0" );
    strcpy(command[ commandNumber++ ],   "pu"  );
}

void
gturtleGetCommand(void)
{
    char s[128];
    int  i;
    
    fprintf(stderr, "gturtle> ");
    fgets(s, 128, stdin);
    sscanf(s, "%s %s", command[commandNumber], parameter[commandNumber]);
    commandNumber++;
}

void
gturtleDraw(void)
{
    double  len, th;
    int     i;
    
    printf("plot [%lf:%lf][%lf:%lf] \"-\" w lp\n", -50.0, 50.0, -50.0, 50.0);
    for (i=0; i<commandNumber; i++) {
        if (strcmp(command[i], "fd") == 0) {
            sscanf(parameter[i], "%lf", &len);
            fd(len);
        } else if (strcmp(command[i], "rt") == 0) {
            sscanf(parameter[i], "%lf", &th);
            rt(len);
        } else if (strcmp(command[i], "pd") == 0) {
            penDown();
        } else if (strcmp(command[i], "pu") == 0) {
            penUp();
        } else if (strcmp(command[i], "init") == 0) {
            init();
        } else if (strcmp(command[i], "q") == 0) {
            quit();
        } else {
            fprintf(stderr, "ERROR: BAD COMMAND !");
            commandNumber = i-1;
        }
    }
    printf("e\n");
    fflush(stdout);
}

/*---- pen library ------*/

double  x, y, angle;
int     pen;

void
fd(double len)
{
    double  tx, ty;
    
    tx = x + len*sin(angle*M_PI/180.0);
    ty = y + len*cos(angle*M_PI/180.0);
    if (pen == DOWN)
        line(x, y, tx, ty);
    x = tx;
    y = ty;
}

void
rt(double th)
{
    angle += th;
    if (th <   0.0) angle += 360.0;
    if (th > 360.0) angle -= 360.0;
}

void
penUp(void)   {pen = 0;}
void
penDown(void) {pen = 1;}

void
init(void)
{
    x = y = angle = 0.0;
    pen = 0;
}

void
line(double x1, double y1, double x2, double y2)
{
    printf("%lf %lf \n", x1, y1);
    printf("%lf %lf \n", x2, y2);
    printf("\n");
}

void
quit(void)
{
    fprintf(stderr, "BYE.\n");
    exit(0);
}

/* file ends here. */
