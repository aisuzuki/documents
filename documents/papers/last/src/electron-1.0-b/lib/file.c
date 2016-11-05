/*	file.c      									*/
/*													*/
/*				  Fri, 27 Sep 2002 03:04:22 +0900	*/
/*			author: ai suzuki<spiral@soulhack.net>	*/

/* code:           */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "field.h"
#include "file.h"

char *
skipto(char *s, char token)
{

    if ((token == '(') || (token == ' '))
        for (; *s != token; s++);

    return s;
}

char *
unpar(char *p)
{
    char  *next;
    int       i;

    if (*p == '(') {
        next = p;
        for (i = 1; p[i] != ')'; i++) {
            next++;
        }
        p[i] = '\0';
        p++;
    }
    return ++next;
}

void
outputFile(anElectron *e)
{
    FILE         *fp;
    anElectron *etmp;

    fp = fopen(filename[OUTPUT_FILE], "w");
    if (!fp)
        perror("fopen: file.c"), exit(EXIT_FAILURE);

    fprintf(fp, "(nx %d) (ny %d) (t %d) (dt %f) (bn %d) \n", nx, ny, t, dt, bn);
    fprintf(fp, "(e\n");
    for (etmp = e; etmp != NULL; etmp = etmp->next) {
        fprintf(fp, "((x %f) (y %f) (vx %f) (vy %f) (q %f) (m %d))\n",  etmp->x,  etmp->y,
                                                                       etmp->vx, etmp->vy,
                                                                        etmp->q,  etmp->m);
    }
    fprintf(fp, ")\n");
    fclose(fp);
}

void
get_field_elem(char *s)
{
    int i, j;
    
    for (i = 0; i < SYMB_F_ELEM; i++) {
        s = skipto(s, '(');
        for (j = 0; *s != ')'; s++, j++) {
            field_symb_table[i][j] = *s;
        }
        s++;
        field_symb_table[i][j] = '\0'; 
    }
}

void
set_field_val(void)
{
    char    valbuf[BUF_SIZE];
    char    symbbuf[BUF_SIZE];
    int     i;

    enum field_symb_elem {
        NX, NY, T, DT, BN
    };

    for (i = 0; i < SYMB_F_ELEM; i++) {
        sscanf(field_symb_table[i], "%s %s", symbbuf, valbuf);
        switch (i) {
            case NX:
                nx = atoi(valbuf);
                break;

            case NY:
                ny = atoi(valbuf);
                break;

            case T:
                t = atoi(valbuf);
                break;

            case DT:
                dt = atof(valbuf);
                break;

           case BN:
                bn = atoi(valbuf);
                break;

           default:
                break;
        }
    }
}

void
get_elect_elem(FILE *fp)
{
    char strbuf[BUF_SIZE];
    char *p, *tmp;
    
    int  i;
   
    /* garbage. */
    if (fgets(strbuf, BUF_SIZE, fp) == NULL)
        perror("get_elect_elem: "), exit(EXIT_FAILURE);

    bn = 0;

    for (; fgets(strbuf, BUF_SIZE, fp) != NULL;) {
        if (*strbuf == ')')
            break; /* eof. */

        tmp = strbuf;
        for (i = 0; i < SYMB_E_ELEM; i++) {
            p = skipto(tmp, '(');
            tmp = unpar(p);
            strcpy(elect_symb_table[bn][i], ++p);
            fprintf(stderr, "table = %s\n", elect_symb_table[bn][i]);
        }
        bn++;
    }
}

void
set_elect_val(anElectron *e)
{
    anElectron *etmp;
    char    valbuf[BUF_SIZE];
    char    symbbuf[BUF_SIZE];
    int     i, n;

    enum elect_symb_elem {
        X, Y, VX, VY, Q, M
    };

    n = 0;
    for (etmp = e; etmp != NULL; etmp = etmp->next) {
        for (i = 0; i < SYMB_E_ELEM; i++) {
            sscanf(elect_symb_table[n][i], "%s %s", symbbuf, valbuf);
            switch (i) {
                case X:
                    etmp->x = atof(valbuf);
                    break;

                case Y:
                    etmp->y = atof(valbuf);
                    break;

                case VX:
                    etmp->vx = atof(valbuf);
                    break;

                case VY:
                    etmp->vy = atof(valbuf);
                    break;

                case  Q:
                    etmp->q = atof(valbuf);
                    break;

                case  M:
                    etmp->m = atoi(valbuf);
                    break;

                default:
                    break;
            }
        }
        n++;
/*        fprintf(stderr, "%f %f \n", etmp->x, etmp->y);*/
/*        fprintf(stderr, "%f %f \n", etmp->vx, etmp->vy);*/
/*        fprintf(stderr, "%f %d \n", etmp->q, etmp->m);*/
    }
}

void
loadFromFile(anElectron *e)
{
    /* global symbol elements. */

    FILE        *fp;
    char    strbuf[BUF_SIZE];

    fp = fopen(filename[INPUT_FILE], "r");
    if (!fp)
        perror("fopen"), exit(EXIT_FAILURE);

    if (fgets(strbuf, BUF_SIZE, fp) == NULL)
        fprintf(stderr, "file is empty. \n"), exit(EXIT_FAILURE);

    get_field_elem(strbuf);
    set_field_val();
    get_elect_elem(fp);
    set_elect_val(e);
     
    fclose(fp);
}

/* file ends here. */
