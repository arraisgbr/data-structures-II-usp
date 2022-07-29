OBJ = compactador.o auxiliar_compactador.o node.o
FLAGS = -std=c++17 -Wall -O2 -pedantic

compactador: compactador.o auxiliar_compactador.o node.o
	g++ $(OBJ) -o compactador

node.o:
	g++ node.cpp $(FLAGS) -c -o node.o

compactador.o:
	g++ compactador.cpp $(FLAGS) -c -o compactador.o

auxiliar_compactador.o:
	g++ auxiliar_compactador.cpp $(FLAGS) -c -o auxiliar_compactador.o

clean:
	rm -r compactador *.o