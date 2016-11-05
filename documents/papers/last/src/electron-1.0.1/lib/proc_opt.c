/* proc_opt.c                               */
/*                                          */
/*      Thu, 26 Sep 2002 04:11:34 +0900     */
/*   author: ai suzuki<spiral@soulhack.net> */

/* code:           */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "field.h"

static char *usage =
    "usage: eg                                                \n"
    " [options]  [arg]                                        \n"
    " --if, -i   <filename>    load from a file.              \n"
    " --of, -o   <filename>    output to a file.              \n"
    " --bn, -b   <number>      generate orderd electrons.     \n"
    " --fn, -f   <number>      output orderd flame to stdout. \n";

void
procOptions(int argc, char *argv[])
{
    static struct option long_options[] = {
        {"if",       1, 0, 'i' },
        {"of",       1, 0, 'o' },
        {"bn",       1, 0, 'b' },
        {"fn",       1, 0, 'f' },
        {"help",     0, 0, 'h' },
        {0,          0, 0,  0  }
    };
    static int opt_end = -1;

    /* by defalut */
    nx = 20;
    ny = 20;
    t  = 100;
    bn =  2;
    fn =  0;
    dt = 0.1;
    dx = FIELD_SIZE / (double)nx;
    dy = FIELD_SIZE / (double)ny;
    
    flag[IF] = OFF;
    flag[OF] = OFF;
    flag[BN] = OFF;
    flag[FN] = OFF;

    memset(filename[INPUT_FILE],  '\0', FILE_NAME_SIZE);
    memset(filename[OUTPUT_FILE], '\0', FILE_NAME_SIZE);

    while (1) {

        int  opt;
        int  option_index = 0;

        opt = getopt_long(argc, argv, "i:o:b:f", 
                            long_options, &option_index);
        if (opt == opt_end) break;

        switch (opt) {
            case 'i' :
                strcpy(filename[INPUT_FILE], optarg);
                flag[IF] = ON;
                break; 
            case 'o' :
                strcpy(filename[OUTPUT_FILE], optarg);
                flag[OF] = ON;
                break;
            case 'b' :
                bn = atoi(optarg);
                flag[BN] = ON;
                break; 
            case 'f' :
                fn = atoi(optarg);
                flag[FN] = ON;
                break; 
            case 'h':
            case '?':
            case  0 :
            default :
                fprintf(stderr, usage);
                exit(EXIT_FAILURE);
                break;
        }
    }
}

/* file ends here. */
