SRC := shortC.c
CC := gcc
CFLAGS := -g -Wall -ansi -pedantic

EXE1 := convert
EXE2 := shortC

all:
	$(CC) $(CFLAGS) -D ENCODE $(SRC) -o $(EXE1)
	$(CC) $(CFLAGS) -D DECODE $(SRC) -o $(EXE2)
