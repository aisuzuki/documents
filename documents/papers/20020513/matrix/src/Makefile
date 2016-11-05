##########################################
#
#  Makefile for Matrix
#
##########################################

GCC=gcc
OPT= -Wall -ansi -pedantic
LIB=lib/
MATRIX=Matrix
AOUT=a.out


makelib: 
	cd $(LIB) && make 

abc: $(MATRIX)
	$(GCC) $(OPT) trans.c $(MATRIX) && \
  $(AOUT)

ae: $(MATRIX)
	$(GCC) $(OPT) root.c $(MATRIX) && \
  $(AOUT)

ab+c: $(MATRIX)
	$(GCC) $(OPT) divide1.c $(MATRIX) && \
  $(AOUT)

a+bc: $(MATRIX)
	$(GCC) $(OPT) divide2.c $(MATRIX) && \
  $(AOUT)

clean: cleanlib
	rm -f a.out $(MATRIX)

cleanlib:
	cd $(LIB) && make clean
