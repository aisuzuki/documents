##########################################
#
#  Makefile for Matrix
#
##########################################

GCC=gcc
LD=ld
MAKE=make
OPT= -g -Wall -ansi -pedantic
MATHLIB= -lm
FIELD=Field

makeobj: *.c
	$(GCC) $(OPT) -c $? 

clean: 
	rm -f *.o *~
