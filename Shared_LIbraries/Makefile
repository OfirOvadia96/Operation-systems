CC=gcc
FLAGS= -Wall -g

all: main1_1 main1_2 main1_3

main1_1: hello_ariel.h hello_ariel.o main1_1.c
	$(CC) $(FLAGS) -o main1_1 hello_ariel.o main1_1.c

main1_2: hello_ariel.h main1_1.c libHello.so
	$(CC) $(FLAGS) main1_1.c -L. -l Hello -o main1_2 
#'export LD_LIBRARY_PATH=.' command that find the lib location

main1_3: hello_ariel.h main1_3.c libHello.so
	$(CC) $(FLAGS) main1_3.c -fPIC -ldl -o main1_3

libHello.so: hello_ariel.h hello_ariel.o
	$(CC) -o libHello.so -shared -fPIC hello_ariel.o

hello_ariel.o: hello_ariel.h hello_ariel.c
	$(CC) $(FLAGS) -c hello_ariel.c

.PHONY: clean all

clean:
	rm -f *.o *.so main1_1 main1_2 main1_3