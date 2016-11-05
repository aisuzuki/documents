##########################################
#
#  Makefile for Matrix
#
##########################################

GCC=gcc
LD=ld
OPT= -Wall -c
MATRIX=Matrix
OBJ=matmul.c matplus.c mattake.c \
    oppmove.c product.c 

all: makelib makeMatrix

makelib: $(OBJ)
	$(GCC) $(OPT) $?

makeMatrix: 
	$(LD) -o ../$(MATRIX) *.o

clean:
	rm -f *.o 
