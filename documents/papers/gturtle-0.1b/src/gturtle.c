/*
 * file: gturtle.c,v
 * Revision: 0.1
 * Author: ai suzuki
 * Date: 2002/08/27 18:06:02
 * Description: Turtle graphics for GNU/Linux
 *
 * Copyright (C) 2002  ai suzuki <spiral@soulhack.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1415927
#endif

#define NAME_SIZE   32
#define BUF_SIZE    128
#define COLORS      8

#define UP    0
#define DOWN  1
typedef int boolean;

static char welcome[] = "*** WELCOME TO GTURTLE! *** \n"
                        "    Author: ai suzuki        \n"
                        "    Aug. 13 2002             \n"
                        "    See <help> to usage      \n";

static char usage[] = "<command list>                                            \n"
                      " << System Command >>                                     \n"
                      "init    <name>             : Generate <name>              \n"
                      "delete  <name>             : Delete <name>                \n"
                      "inspect <name>             : Inspect <name>               \n"
                      "inspectall                 : Inspect all turtles          \n"
                      "history <name>             : Command History              \n"
                      "load    <file>             : Load a command file          \n"
                      "save <turtle> <file>       : Save <turtle> to <file>      \n"
                      "saveall <file>             : Save all turtles to <file>   \n"
                      "ls                         : List directory contents      \n"
                      "bye (or q)                 : Exit gturtle                 \n"
                      "list                       : List turtles                 \n"
                      "colorlist                  : List colors (8 colors)       \n"
                      "help                       : Show this menu               \n"
                      " << Messages >>                                           \n"
                      " <turtle> pd               : <turtle> lowers his pen      \n"
                      " <turtle> pu               : <turtle> lifts his pen       \n"
                      " <turtle> home             : <turtle> goes home           \n"
                      " <turtle> fd <length>      : <turtle> goes ahead          \n"
                      " <turtle> bk <length>      : <turtle> goes back           \n"
                      " <turtle> rt <theta>       : <turtle> turns right         \n"
                      " <turtle> lt <theta>       : <turtle> turns left          \n"
                      " <turtle> color <colorname>: <turtle> get <colorname> pen \n"
                      " <turtle> undo             : Undoing a command            \n";

static char errorMessage[] = "ERROR: BAD COMMAND. \n";

static char colorName[COLORS][NAME_SIZE] = {  "red",     "green",   "blue", "purple", 
                                             "cyan", "darkbrown", "orange",  "brown" };
static int fieldsize; 

/*----------------------------------------------------------------------*/ 
/*                                                                      */
/* < Model >                                                            */ 
/* Class Category: Turtle                                               */ 
/*                                                                      */
/* Class Methods                                                        */ 
/*    Category: Instance Creation                                       */ 
/*        + newTurtle                                                   */
/*    Category: Initialize                                              */ 
/*        + MakeTurtle                                                  */
/* Instance Methods                                                     */ 
/*    Category: Accessing                                               */ 
/*        + locationX(Turtle *tp)                                       */
/*        + locationY(Turtle *tp)                                       */
/*        + setX(Turtle *tp, double x)                                  */
/*        + setY(Turtle *tp, double y)                                  */
/*        + yourAngle(Turtle *tp)                                       */
/*        + setColor(Turtle *tp, char *colorname)                       */
/*        + *penColor(Turtle *tp)                                       */
/*        + history(Turtle *tp)                                         */
/*        + setAngle(Turtle *tp, double th)                             */
/*        + setName(Turtle *tp, char *name)                             */
/*        + *self(Turtle *tp)                                           */
/*    Category: Testing                                                 */ 
/*        + isDown(Turtle *tp)                                          */
/*        + isUp(Turtle *tp)                                            */
/*    Category: Drawing                                                 */
/*        + turnRight(Turtle *tp, double th)                            */
/*        + turnLeft(Turtle *tp, double th)                             */
/*        + Forward(Turtle *tp, double len)                             */
/*        + Back(Turtle *tp, double len)                                */
/*        + home(Turtle *tp)                                            */
/*        + penDown(Turtle *tp)                                         */
/*        + penUp(Turtle *tp)                                           */
/*    Category: Private                                                 */
/*        + line(int color, double x1, double y1, double x2, double y2) */
/*        + undo(Turtle *tp)                                            */
/*        + isExistColor(char *colorname)                               */
/*        + Replot(void)                                                */
/*                                                                      */
/*----------------------------------------------------------------------*/

/*--------- Instance Variable. ----------------*/ 
struct _turtle {

    double          x, y, angle;
    int             pen;
    int             color;
    int             commandNumber;
    char            name[NAME_SIZE];
    char            command[BUF_SIZE][BUF_SIZE];
    char            parameter[BUF_SIZE][BUF_SIZE];
    struct _turtle *prev, *next;

};

typedef struct _turtle Turtle;

/* ^Instance Variable */
/*--------------------------------------------- */

/*----------- Class Variable. -------------------*/

/* ^Class Variable */
/*-----------------------------------------------*/

/*----------Message Selectors -------------------*/
/* Class Message  */

Turtle *newTurtle(void);
Turtle *MakeTurtle(char *name);

/* ^Class Message  */
/*----------------------------------------------*/ 
/* Instance Message  */

double   locationX(Turtle *tp);
double   locationY(Turtle *tp);
void     setX(Turtle *tp, double x);
void     setY(Turtle *tp, double y);
void     setAngle(Turtle *tp, double th);
double   yourAngle(Turtle *tp);
void     setColor(Turtle *tp, char *colorname);
char    *penColor(Turtle *tp);
void     setName(Turtle *tp, char *name);
char    *self(Turtle *tp);
void     history(Turtle *tp);
boolean  isDown(Turtle *tp);
boolean  isUp(Turtle *tp);
void     turnRight(Turtle *tp, double th);
void     turnLeft(Turtle *tp, double th);
void     Forward(Turtle *tp, double len);
void     Back(Turtle *tp, double len);
void     home(Turtle *tp);
void     penDown(Turtle *tp);
void     penUp(Turtle *tp);
void     undo(Turtle *tp);
void     Do(Turtle *tp, int index);
void     line(int color, double x1, double y1, double x2, double y2);
int      isExistColor(char *colorname);
void     Replot(void);

/* ^Instance Message  */
/*----------------------------------------------*/ 


/*-------------- Class Method ------------------*/
/*----------------------------------------------*/
/*                                              */ 
/*   Message Category:                          */ 
/*     Initialization                           */
/*                                              */ 
/*----------------------------------------------*/

/* Instance Creation. */
Turtle *
newTurtle(void)
{
    Turtle  *tp;

    tp = (Turtle *)malloc(sizeof(Turtle));
    if (!tp)
        perror("initialize: turtle"), exit(1);

    return tp;
}

/* Initialize. */
Turtle *
MakeTurtle(char *name)
{
    Turtle  *tp;

    tp = newTurtle();
    
    setX(tp, 0.0);
    setY(tp, 0.0);
    setAngle(tp, 0.0);
    tp->commandNumber = 0;
    setName(tp, name);
    setColor(tp, "red");
    tp->next = NULL;

    penDown(tp);
    Forward(tp, 1.0);
    penUp(tp);
    strcpy(tp->command[ tp->commandNumber++ ],   "pd"  );
    strcpy(tp->command[ tp->commandNumber   ],   "fd"  );
    strcpy(tp->parameter[ tp->commandNumber++ ], "1.0" );
    strcpy(tp->command[ tp->commandNumber++ ],   "pu"  ); 

    return tp;
}

/* ^Class Method. */
/*-----------------------------------------------*/

/*-------------- Instance Method ----------------*/
/*-----------------------------------------------*/
/*                                               */ 
/*   Message Category:                           */ 
/*         Acsessing                             */
/*                                               */ 
/*-----------------------------------------------*/

double
locationX(Turtle *tp) { return tp->x; }
double
locationY(Turtle *tp) { return tp->y; }
void
setX(Turtle *tp, double x) { tp->x = x; }
void
setY(Turtle *tp, double y) { tp->y = y; }

void
setAngle(Turtle *tp, double th) { tp->angle = th; }
double
yourAngle(Turtle *tp) { return tp->angle; }

void
setColor(Turtle *tp, char *colorname)
{ 
    int index;

    if ((index = isExistColor(colorname)) < 0)
        fprintf(stderr, "no such a color: %s\n", colorname);
    else
        tp->color = index+1;
}
char *
penColor(Turtle *tp) { return colorName[tp->color-1]; }

void
setName(Turtle *tp, char *name) { strcpy(tp->name, name); }
char *
self(Turtle *tp) { return tp->name; }

void
history(Turtle *tp)
{
    int i;

    fprintf(stderr, "name: \"%s\"\n", self(tp));
    for (i = 0; i < tp->commandNumber; i++)
        fprintf(stderr, "%s %s\n", tp->command[i], tp->parameter[i]);

    fprintf(stderr, "command: %d\n", tp->commandNumber);
}

/* Accessing.  */
/*------------------------------------------------*/

/*-----------------------------------------------*/
/*                                               */ 
/*   Message Category:                           */ 
/*         Testing                               */
/*                                               */ 
/*-----------------------------------------------*/

boolean
isDown(Turtle *tp)  { return tp->pen ? DOWN : UP; }
boolean
isUp(Turtle *tp)    { return !isDown(tp); }

/* Testing.  */
/*------------------------------------------------*/

/*-----------------------------------------------*/
/*                                               */ 
/*   Message Category:                           */ 
/*         Drawing                               */
/*                                               */ 
/*-----------------------------------------------*/

/* TurnRight  */
void
turnRight(Turtle *tp, double th)
{
    tp->angle += th;
    if (th <   0.0) tp->angle += 360.0;
    if (th > 360.0) tp->angle -= 360.0;    
}

/* TurnLeft  */
void
turnLeft(Turtle *tp, double th)
{
    turnRight(tp, -th);
}

void
Forward(Turtle *tp, double len)
{
    double  tx, ty;

    tx = tp->x + len*sin(tp->angle*M_PI/180.0);
    ty = tp->y + len*cos(tp->angle*M_PI/180.0);
    if (isDown(tp))
        line(tp->color, tp->x, tp->y, tx, ty);
    tp->x = tx;
    tp->y = ty;
}

void
Back(Turtle *tp, double len)
{
    Forward(tp, -len);
}

void
home(Turtle *tp)
{
    setX(tp, 0.0);
    setY(tp, 0.0);
}

void
undo(Turtle *tp)
{
    if (tp->commandNumber < 2) {
        tp->commandNumber = 0;
    } else {
        tp->commandNumber -= 2;
        Replot();
    }
}

void
Do(Turtle *tp, int index)
{
    float len, th;

    if (strcmp(tp->command[tp->commandNumber-1], "undo") == 0) {
        undo(tp);
    } else if (strcmp(tp->command[index], "fd") == 0) {
        sscanf(tp->parameter[index], "%f", &len);
        Forward(tp, len);
    } else if (strcmp(tp->command[index], "bk") == 0) {
        sscanf(tp->parameter[index], "%f", &len);
        Back(tp, len);
    } else if (strcmp(tp->command[index], "rt") == 0) {
        sscanf(tp->parameter[index], "%f", &th);
        turnRight(tp, th);
    } else if (strcmp(tp->command[index], "lt") == 0) {
        sscanf(tp->parameter[index], "%f", &th);
        turnLeft(tp, th);
    } else if (strcmp(tp->command[index], "pd") == 0) {
        penDown(tp);
    } else if (strcmp(tp->command[index], "pu") == 0) {
        penUp(tp);
    } else if (strcmp(tp->command[index], "color") == 0) {
        setColor(tp, tp->parameter[index]);
    } else if (strcmp(tp->command[index], "home") == 0) {
        home(tp);
    } else if (strcmp(tp->command[index], "history") == 0) {
        history(tp);
    } else {
        fprintf(stderr, "%s", errorMessage);
        tp->commandNumber -= 1;
    }
}

void
penDown(Turtle *tp) { tp->pen = DOWN; }
void
penUp(Turtle *tp)   { tp->pen = UP; }

/* Drawing.  */
/*------------------------------------------------*/

/*-----------------------------------------------*/
/*                                               */ 
/*   Message Category:                           */ 
/*         Private                               */
/*                                               */ 
/*-----------------------------------------------*/

void
line(int color, double x1, double y1, double x2, double y2)
{
    printf("plot \"-\" w lp %d \n", color); 
    printf("%f %f \n", x1, y1);
    printf("%f %f \n", x2, y2);
    printf("e\n");   
    fflush(stdout);
}

int
isExistColor(char *colorname)
{
    int  i;

    for (i = 0; i < COLORS; i++) {
        if (strcmp(colorName[i], colorname) == 0)
            return i;
    }    
    /* color not found. */
    return -1;
}

/* Private.  */
/*------------------------------------------------*/

/*---------------------------------------------------------------------*/ 
/*                                                                     */
/* < Controller >                                                      */ 
/* Class Category: Turtle Controller                                   */ 
/*                                                                     */
/* Class Methods                                                       */ 
/*                                                                     */
/* Instance Methods                                                    */ 
/*    Category: Initialize                                             */ 
/*        + SystemInit(void)                                           */
/*    Category: Control Defaults                                       */ 
/*        + getCommand(void)                                           */
/*    Category: Command Accessing                                      */ 
/*        + init(char *name)                                           */
/*        + delete(char *name)                                         */
/*        + inspectIt(char *name)                                      */
/*        + inspectAll(void)                                           */
/*        + showColors(void)                                           */
/*        + Save(char *name, char *filename, char *mode)               */
/*        + SaveAll(char *filename)                                    */
/*        + Load(char *filename)                                       */
/*        + ls(void)                                                   */
/*        + help(void)                                                 */
/*        + bye(void)                                                  */
/*        + TurtleList(Turtle *tp)                                     */
/*    Category: Testing                                                */ 
/*        + isEmpty(void)                                              */
/*        + isSame(Turtle *tp, char *name)                             */
/*    Category: Private                                                */ 
/*        + fileCheck(char *filename)                                  */
/*        + *addTurtle(Turtle *tp)                                     */
/*        + deleteTurtle(Turtle *tp)                                   */
/*        + clearData(Turtle *tp)                                      */
/*        + *searchTurtle(char *name)                                  */
/*                                                                     */
/*---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/ 
/*                                                                     */
/* < View >                                                            */ 
/* Class Category: Turtle View                                         */ 
/*                                                                     */
/* Class Methods                                                       */ 
/*                                                                     */
/* Instance Methods                                                    */ 
/*    Category: Drawings                                               */ 
/*        + Draw(void)                                                 */
/*        + WindowClear(void)                                          */
/*                                                                     */
/*---------------------------------------------------------------------*/
void     Draw(void);
void     WindowClear(void);

boolean  isEmpty(void);
boolean  isSame(Turtle *tp, char *name);
Turtle  *addTurtle(Turtle *tp);
void     deleteTurtle(Turtle *tp);
void     ls(void);
void     help(void);
void     bye(void);
void     init(char *name);
void     delete(char *name);
void     showColors(void);
void     inspectIt(char *name);
void     inspectAll(void);
boolean  getCommand(void);
Turtle  *searchTurtle(char *name);
void     clearData(Turtle *tp);
void     SystemInit(void);
void     TurtleList(Turtle *tp);
void     Save(char *name, char *filename, char *mode);
void     SaveAll(char *filename);
void     Load(char *filename);
int      fileCheck(char *filename);

/*----------- Class Variable. -------------------*/

Turtle     *frontPointer  = NULL;
Turtle     *rearPointer   = NULL;
Turtle     *activeTurtle  = NULL;

/* ^ClassVariable */
/*-----------------------------------------------*/

boolean isEmpty() { return rearPointer == NULL; }

/* if 'tp's name is 'name', return 1, otherwise 0 */
boolean isSame(Turtle *tp, char *name) { return !strcmp(tp->name, name); }

Turtle *
addTurtle(Turtle *tp)
/* 
   Useage:
   Make a new turtle "hoge" and 
   add the list of end.

   addTurtle(MakeTurtle("hoge"));
*/
{
    if (isEmpty()) {
        frontPointer = tp;
        tp->prev     = NULL;
    } else {
        rearPointer->next = tp;
        tp->prev          = rearPointer;
    }
    rearPointer = tp;
    return tp;
}

void
deleteTurtle(Turtle *tp)
{
    /* if there is no more than 'tp'. */
    if (frontPointer == rearPointer) {
        frontPointer = rearPointer = NULL; 
        WindowClear();

    /* if 'tp' is top of list */
    } else if (tp->prev == NULL) {
        tp->next->prev = NULL;
        frontPointer   = tp->next; 
    
    /* if 'tp' is rear of list */
    } else if (tp->next == NULL) {
        tp->prev->next = NULL;
        rearPointer    = tp->prev;
    } else {
        tp->prev->next = tp->next;
        tp->next->prev = tp->prev;
    }
    free(tp);
}

void ls(void) { system("ls -F --color=auto > /dev/stderr "); }
void help(void) { fprintf(stderr, "%s", usage); }

void 
bye(void)
{
    fprintf(stderr, "BYE.\n");
    exit(0);
}

void 
init(char *name)
{
    if (*name == '\0')
        fprintf(stderr, "ERROR: please name a turtle.\n"); 
    else if (searchTurtle(name)) 
        fprintf(stderr, "ERROR: %s is exist. name other.\n", name); 
    else     
        addTurtle(MakeTurtle(name));
}

void 
delete(char *name)
{
    Turtle *tp;
    if (!(tp = searchTurtle(name)))
        fprintf(stderr, "ERROR: no such a turtle.\n"); 
    else
        deleteTurtle(tp);
}

void
showColors(void)
{
    int i;

    fprintf(stderr, "<color list>:");    
    for (i = 0; i < COLORS; i++) {
        if ((i%4) == 0)
            fprintf(stderr, "\n");
        fprintf(stderr, "  \"%s\" ", colorName[i]);
    }
    fprintf(stderr, "\n");
}

void
inspectIt(char *name)
{
    Turtle *tp;
    if (!(tp = searchTurtle(name))) {
        fprintf(stderr, "ERROR: no such a turtle.\n"); 
    } else {
    fprintf(stderr, "--<Turtle Inspector>--\n");
    fprintf(stderr, "name     : %s\n", self(tp));
    fprintf(stderr, "now      : x = %f, y = %f\n", locationX(tp), locationY(tp));
    fprintf(stderr, "distance : %f\n", yourAngle(tp));
    fprintf(stderr, "pen      : %s\n", isDown(tp) ? "down" : "up");
    fprintf(stderr, "pen color: %s\n", penColor(tp));
    fprintf(stderr, "command  : %d\n", tp->commandNumber);
    }
}

void
inspectAll(void)
{
    Turtle *tp;
    if (isEmpty())
        fprintf(stderr, "no turtle.\n"); 
    else
        for (tp = frontPointer; tp != NULL; tp = tp->next)
            inspectIt(self(tp));
}

boolean
getCommand()
{
    Turtle *tp;
    
    char s[BUF_SIZE];
    char car[BUF_SIZE];
    char cdr[BUF_SIZE];
    char cddr[BUF_SIZE];

    /* initialization. no garbage */
/*    memset(car, '\0', BUF_SIZE);*/
/*    memset(cdr, '\0', BUF_SIZE);*/
/*    memset(cddr,'\0', BUF_SIZE);*/
    *car  = '\0';
    *cdr  = '\0';
    *cddr = '\0';
    
    fprintf(stderr, "gturtle> ");
    fgets(s, BUF_SIZE, stdin);
    sscanf(s, "%s %s %s", car, cdr, cddr);

    /* System Command */
    if (strcmp(car, "ls") == 0) {
        ls();
    } else if (strcmp(car, "list") == 0) {
        tp = frontPointer;
        TurtleList(tp);
    } else if (strcmp(car, "load") == 0) {
        Load(cdr);
    } else if (strcmp(car, "save") == 0) {
        Save(cdr, cddr, "w+");
    } else if (strcmp(car, "saveall") == 0) {
        SaveAll(cdr);
    } else if (strcmp(car, "help") == 0) {
        help();
    } else if (strcmp(car, "colorlist") == 0) {
        showColors();
    } else if ((strcmp(car, "bye") == 0) ||
               (strcmp(car, "q") == 0)) {
        bye();

    } else if (strcmp(car, "init") == 0) {
        init(cdr);
    } else if (strcmp(car, "delete") == 0) {
        delete(cdr);
    } else if (strcmp(car, "inspect") == 0) {
        inspectIt(cdr);
    } else if (strcmp(car, "inspectall") == 0) {
        inspectAll();

    /* Message Sending */
    } else if (!(activeTurtle = searchTurtle(car))) {
        fprintf(stderr, "ERROR: no such a turtle %s\n", car);
    } else {
        strcpy(activeTurtle->command[activeTurtle->commandNumber], cdr);
        strcpy(activeTurtle->parameter[activeTurtle->commandNumber], cddr);
        activeTurtle->commandNumber++;
        return 1;
    }
    return 0;
}

Turtle *
searchTurtle(char *name)
{
    Turtle *tp;
    tp = frontPointer;

    for (; tp != NULL; ) {
        if (isSame(tp, name))
            return tp;
        tp = tp->next; 
    }
    return NULL;
}

void
Replot(void)
{
    Turtle  *tp, *last;
    int     i;

    tp = last = frontPointer;
    clearData(tp);
    WindowClear();
    if (!isEmpty()) {
        tp = last = frontPointer;

    /* ここらへん死ぬ程嫌。 */
        for (i = 0; i < last->commandNumber; i++) {
            for (tp = frontPointer; tp != NULL; tp = tp->next) {
                if (i < tp->commandNumber) {
                    Do(tp, i);
                    if (i+1 < tp->commandNumber)
                        last = tp;
                }
            } /* for: (tp..  */
        } /* for: (i=..  */
    }
}

void
clearData(Turtle *tp)
{
    if (tp == NULL)
        return;

    home(tp);
    tp->angle = 0.0;
    setColor(tp, "red");
    clearData(tp->next);
}

void
SystemInit(void)
{
    int h;

    h = fieldsize / 2;
    fprintf(stderr, "%s", welcome);
    printf("set multiplot                         \n"
           "set xrange[-%d:%d]                    \n"
           "set yrange[-%d:%d]                    \n"
           "set nokey                             \n"
           "set nolabel                           \n"
           "set grid                              \n"
           "set title \"turtle graphics\"         \n"
           "set size square                       \n"
           "set xtics 10                          \n"
           "set ytics 10                          \n", h, h, h, h);
    WindowClear();
}

void
TurtleList(Turtle *tp)
{
    if (tp == NULL)
        return;

    fprintf(stderr, "%s\n", self(tp)); 
    TurtleList(tp->next);
}

void
Save(char *name, char *filename, char *mode)
{
    FILE    *fp;
    Turtle  *tp;
    int       i;
    
    if (!(tp = searchTurtle(name))) {
        fprintf(stderr, "ERROR: no such a turtle %s\n", name);
    } else if (!(fp = fopen(filename, mode))) {
        perror("<Save>");
        fprintf(stderr, "see help \"save\".\n");
    } else {
        fprintf(fp, "(%s \n", name);
        for (i=3; i<tp->commandNumber; i++) {
            fprintf(fp, "\t%s %s\n", tp->command[i], tp->parameter[i]);
        }
        fprintf(fp, ")\n");
        fclose(fp);
    }
}

void
SaveAll(char *filename)
{
    Turtle      *tp;
    struct stat  stbuf;
    
    if (isEmpty()) {
        fprintf(stderr, "no turtle.\n");
    } else {
        /* 'saveall' can not over write a file. */ 
        if (stat(filename, &stbuf) == -1) {
            for (tp = frontPointer; tp != NULL; tp = tp->next) {
                Save(self(tp), filename, "a");
            }
        } else {
            fprintf(stderr, "%s is exist. name another.\n", filename);
        }
    }
}

void
Load(char *filename)
{
    FILE   *fp;
    Turtle *tp;
    char     s[BUF_SIZE];
    char  name[BUF_SIZE];
    char   car[BUF_SIZE];
    char   cdr[BUF_SIZE];

    if (fileCheck(filename)) {
        fp = fopen(filename, "r");
        if (!fp) {
            perror("<Load>"),
            fprintf(stderr, "see help \"load\".\n");
        } else {
            for (*car = '\0', *cdr = '\0' ; fgets(s, BUF_SIZE, fp) != NULL; *car = '\0', *cdr = '\0'){
                sscanf(s, "%s, %s", car, cdr);
                if (*car == '(') {
                    strcpy(name, car+1);
                    if (!(tp = searchTurtle(name)))
                        tp = addTurtle(MakeTurtle(name));

                    for (*car = '\0', *cdr = '\0' ; ; *car = '\0', *cdr = '\0'){
                        fgets(s, BUF_SIZE, fp);
                        sscanf(s, "%s %s", car, cdr);
                        if (*car == ')')
                            break;
                        strcpy(tp->command[tp->commandNumber], car);
                        strcpy(tp->parameter[tp->commandNumber], cdr);
                        tp->commandNumber++; 
                        Do(tp, tp->commandNumber-1);
                    }
                }    
            }
        }
    fclose(fp);
    }
}

int
fileCheck(char *filename)
{
    FILE *fp; 
    char  s[BUF_SIZE];
    int   index;
    int   i, openPar, closePar;
 
    openPar = closePar = 0;
    index = strlen(filename)-3;

    if ((strcmp(&filename[index], ".gt") == 0)) {
        fp = fopen(filename, "r");
        if (!fp)
            perror("fileCheck");

        for (; fgets(s, 128, fp) != NULL;) {
            for (i = 0; s[i] != '\0'; i++){
                if (s[i] == '(')
                    openPar++;
                else if (s[i] == ')')
                    closePar++;
            }
        }
        if (openPar == closePar) {
            fclose(fp);
            return 1;
        } else {
            fprintf(stderr, "parse error: no mach '(' and ')'\n"
                            "check \"%s\".\n", filename);
            fclose(fp);
            return 0;
        } 
    } else {
        fprintf(stderr, "bad file. enter \"*.gt\". \n");
        return 0;
    }
}

void
WindowClear(void)
{
    printf("clear\n");
    printf("plot \"-\" w lp\n"); 
    printf("-1000 1000\n");
    printf("-1001 1001 \n");
    printf("e\n");   
    fflush(stdout);
}

void
Draw()
{
    if (!isEmpty())
        Do(activeTurtle, activeTurtle->commandNumber-1);
}


int main(int argc, char **argv)
{
    fieldsize = atoi(*(argv+1));
    SystemInit();
    while (1) {
        if (getCommand())
            Draw();
    }
    return 0;
}

/* File ends here. */
