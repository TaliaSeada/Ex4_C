CC=gcc
FLAGS= -Wall -g

#make all
all: graph

.PHONY: clean
#make clean
clean:
	rm -f *.o *.a *.so graph

graph: main.o
	$(CC) $(FLAGS) -o graph main.c

main.o: main.c algo.o Edge.o graph.o
	$(CC) $(FLAGS) -c main.c

algo.o: algo.h algo.c
	$(CC) $(FLAGS) -c algo.c

Edge.o: Edge.h Edge.c
	$(CC) $(FLAGS) -c Edge.c

graph.o: graph.h graph.c Edge.h
	$(CC) $(FLAGS) -c graph.c


