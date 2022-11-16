#makefile for task3 on operation system


all: solution

solution: solution.o
	gcc solution.o -pthread -lm -o solution

solution.o: solution.c
	gcc -c solution.c

.PHONY: clean

clean: 
	rm -f *.o solution
