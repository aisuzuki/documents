##########################################
#
#  Makefile for Matrix
#
##########################################

GCC=gcc
OPT= -Wall -ansi -pedantic
LIB=lib/
PERMUTATION=Permutation

LIB=sign.c
MAIN=main.c
AOUT=a.out

test: $(PERMUTATION)
	$(GCC) $(OPT) $(MAIN) $(PERMUTATION) && \
  $(AOUT)

$(PERMUTATION):
	$(GCC) $(OPT) -o $(PERMUTATION) -c $(LIB)

clean:
	rm -f a.out $(PERMUTATION) *.o
