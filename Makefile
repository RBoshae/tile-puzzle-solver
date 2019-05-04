COMPILE = g++
FLAGS =-Wall -Werror -ansi -pedantic -g -std=c++1z

OBJS = ./bin/Board.o ./bin/A_Star.o ./bin/Node.o

all: ./src/main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -g ./src/main.cpp $(OBJS) -o ./bin/puzzle_solver

./bin/Board.o: ./include/Board.h ./src/Board.cpp
	$(COMPILE) $(FLAGS) -c ./src/Board.cpp -o ./bin/Board.o

./bin/A_Star.o: ./include/A_Star.h ./src/A_Star.cpp
	$(COMPILE) $(FLAGS) -c ./src/A_Star.cpp -o ./bin/A_Star.o

./bin/Node.o: ./include/Node.h ./src/Node.cpp
	$(COMPILE) $(FLAGS) -c ./src/Node.cpp -o ./bin/Node.o

clean:
	rm -rf ./bin/*
