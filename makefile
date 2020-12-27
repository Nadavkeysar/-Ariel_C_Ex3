# vars
CC = gcc
WGC = -Wall -g
C = -c

# all
all: isort txtfind

isort: isort.o isort.h
	$(CC) -Wall isort.o -o isort

txtfind: txtfind.o txtfind.h
	$(CC) -Wall txtfind.o -o txtfind

isort.o: isort.c
	$(CC) $(WGC) $(C) isort.c

txtfind.o: txtfind.c
	$(CC) $(WGC) $(C) txtfind.c

# removing all .o, .out, isort and txtfind (exeute) files
clean:
	rm -f *.o *.out *.a *.so main isort txtfind
