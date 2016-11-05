##########################################
#
#  Makefile for Matrix
#
##########################################

GCC=gcc
OPT= -Wall -g -ansi -pedantic
MATHLIB= -lm
FIELD=Field

SCALE_MAIN=scaleFieldMain.c
VECTOR_MAIN=vectorFieldMain.c
FIELD_SRC=field.c

scale: $(FIELD)
	$(GCC) $(OPT) $(SCALE_MAIN) $(FIELD) $(MATHLIB)

vector: $(FIELD)
	$(GCC) $(OPT) $(VECTOR_MAIN) $(FIELD) $(MATHLIB)

$(FIELD):
	$(GCC) $(OPT) -o $(FIELD) -c $(FIELD_SRC) $(MATHLIB)

clean: 
	rm -f a.out $(FIELD) *.o  *~ ?? 
