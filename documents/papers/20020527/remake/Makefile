##########################################
#
#  Makefile for Matrix
#
##########################################

GCC=gcc
MAKE=make
OPT= -g -Wall -ansi -pedantic
MATHLIB= -lm
FIELD=Field
LIB=lib

MAIN=main.c

world: makelib 
	$(GCC) $(OPT) $(MAIN) $(LIB)/*.o $(MATHLIB)

makelib: 
	cd $(LIB) && $(MAKE)

clean: cleanlib
	rm -f a.out $(FIELD) *.o ?? *~ 

cleanlib: 
	cd $(LIB) && $(MAKE) clean
