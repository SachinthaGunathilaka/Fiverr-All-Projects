all: nim.h nim.c alphanim.c nimhelp.c
	gcc -o nim.o alphanim.c nimhelp.c nim.h nim.c -Wall -pedantic -std=c99

test:
	./nim.o 1 1 5 3 4 6 2