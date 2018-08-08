COMPILE = g++
FLAGS =-Wall -ansi -pedantic

OBJS = ./bin/Board.o ./bin/Node.o

all: ./src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -g ./src/main.cpp $(OBJS) -o ./bin/puzzle_solver

./bin/Board.o: ./include/Board.h ./src/Board.cpp
	$(COMPILE) $(FLAGS) -c ./src/Board.cpp -o ./bin/Board.o

./bin/Node.o: ./include/Node.h ./src/Node.cpp
	$(COMPILE) $(FLAGS) -c ./src/Node.cpp -o ./bin/Node.o

clean:
	rm -rf ./bin/*
