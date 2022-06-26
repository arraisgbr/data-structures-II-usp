OBJ = main.o grafos.o
FLAGS = -std=c++17 -Wall -O2 -pedantic

main: main.o grafos.o
	g++ $(OBJ) -o main

main.o:
	g++ main.cpp $(FLAGS) -c -o main.o

grafos.o:
	g++ grafos.cpp $(FLAGS) -c -o grafos.o

clean:
	rm -r *.o main