/* file.h                                   */
/*                                          */
/*   Thu, 26 Sep 2002 18:44:23 +0900        */
/*   author: ai suzuki<spiral@soulhack.net> */

/* code:           */

enum size {
    SYMB_F_ELEM = 5,
    SYMB_E_ELEM = 6,
    MAX_E_SIZE  = 500
};

char field_symb_table[SYMB_F_ELEM][BUF_SIZE];
char elect_symb_table[MAX_E_SIZE][SYMB_F_ELEM][BUF_SIZE];

int  max_elect;

char *skipto(char *s, char token);
char *unpar(char *p);
void  outputFile(anElectron *e);
void  get_field_elem(char *s);
void  set_field_val(void);
void  get_elect_elem(FILE *fp);
void  set_elect_val(anElectron *e);
void  loadFromFile(anElectron *e);

/* file ends here. */
