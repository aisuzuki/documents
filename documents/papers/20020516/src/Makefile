##########################################
#
#  Makefile for Matrix
#
##########################################

GCC=gcc
OPT= -Wall -g -ansi -pedantic
MATHLIB= -lm
PRODUCT=Product

LIB=product.c
DOT_MAIN=dotProductMain.c
CROSS_MAIN=crossProductMain.c
CROSS_WITHANGLE_MAIN=crossProductWithAngleMain.c
AOUT=a.out

dot: $(PRODUCT)
	$(GCC) $(OPT) $(DOT_MAIN) $(PRODUCT) $(MATHLIB) && \
  $(AOUT) | gnuplot

cross: $(PRODUCT)
	$(GCC) $(OPT) $(CROSS_MAIN) $(PRODUCT) $(MATHLIB) && \
  $(AOUT) | gnuplot  

cross_a: $(PRODUCT)
	$(GCC) $(OPT) $(CROSS_WITHANGLE_MAIN) $(PRODUCT) $(MATHLIB) && \
  $(AOUT)

$(PRODUCT): 
	$(GCC) $(OPT) -o $(PRODUCT) -c $(LIB)

clean: 
	rm -f a.out $(PRODUCT) *.o  *.bak
