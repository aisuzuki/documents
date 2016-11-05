#########################################
#
#   Makefile for gturtle.c
#
#########################################

GCC=gcc
RM=/bin/rm
SRC=gturtle.c
SRCDIR=src
BIN=gturtle-bin
BINDIR=bin
GTURTLE=gturtle
AOUT=a.out

# by default
FIELDSIZE=200

MATHLIB=-lm

all:
	$(GCC) -Wall -ansi -pedantic -O5 -o $(PWD)/$(BINDIR)/$(BIN) $(PWD)/$(SRCDIR)/$(SRC) $(MATHLIB)
	echo "#!/bin/sh" > $(PWD)/$(BINDIR)/$(GTURTLE)
	echo "($(PWD)/$(BINDIR)/$(BIN) $(FIELDSIZE))| gnuplot" >> $(PWD)/$(BINDIR)/$(GTURTLE)
	chmod 755 $(PWD)/$(BINDIR)/$(GTURTLE)

clean:
	$(RM) $(PWD)/$(BINDIR)/$(BIN) $(PWD)/$(BINDIR)/$(GTURTLE)

veryclean:
	$(RM) *~
