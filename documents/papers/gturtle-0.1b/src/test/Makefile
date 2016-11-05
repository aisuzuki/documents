#########################################
#
#   Makefile for tekito.c
#
#########################################

GCC=gcc
RM=/bin/rm
SRC=tekito.c
GTURTLE=gturtle
AOUT=a.out

# by default
FIELDSIZE=200

MATHLIB=-lm

all:
	$(GCC) -Wall -ansi -pedantic -O6 $(SRC) $(MATHLIB)
	echo "#!/bin/sh" > $(GTURTLE)
	echo "($(AOUT) $(FIELDSIZE))| gnuplot" >> $(GTURTLE)
	chmod 755 $(GTURTLE)

clean:
	$(RM) $(AOUT) $(GTURTLE)

veryclean:
	$(RM) *~
