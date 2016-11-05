##########################################
#
#  Makefile for Matrix
#
##########################################

GCC=gcc
MAKE=make
MAKEFILE=Makefile
OPT= -g -Wall -ansi -pedantic
MATHLIB= -lm
FIELD=Field
LIB=lib
GNUPLOT=gnuplot

BINDIR=$(PWD)/bin

BIN=electrons-bin
OBJ=electrons

MAIN=main.c

world: makelib 
	$(GCC) $(OPT) -o $(BINDIR)/$(BIN) $(MAIN) $(LIB)/*.o $(MATHLIB) &&\
	echo "#!/bin/sh" >> $(BINDIR)/$(OBJ)
	echo "$(BINDIR)/$(BIN) | $(GNUPLOT)" >> $(BINDIR)/$(OBJ)
	chmod 755 $(BINDIR)/$(OBJ)

makelib: 
	make -C $(LIB)

clean: cleanlib
	rm -f a.out $(FIELD) *.o ?? *~ $(BINDIR)/$(BIN) $(BINDIR)/$(OBJ)

cleanlib: 
	make -C $(LIB) clean
