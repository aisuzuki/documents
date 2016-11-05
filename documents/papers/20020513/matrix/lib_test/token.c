#include <stdio.h>
#include "matrix.h"

int  tokenp(const char c)
{
  return (c == ' ' || c == '\t' 
       || c == '(' || c == '\n'
       || c == '\0')  ? T : NIL; 
       
}
