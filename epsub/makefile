OBJ = auxiliar_compactador.o node.o
FLAGS = -std=c++17 -Wall -O2 -pedantic

compactador: compactador.o auxiliar_compactador.o node.o
	g++ compactador.o $(OBJ) -o compactar

descompactador: descompactador.o auxiliar_compactador.o node.o
	g++ descompactador.o $(OBJ) -o descompactar

node.o:
	g++ node.cpp $(FLAGS) -c -o node.o

compactador.o:
	g++ compactador.cpp $(FLAGS) -c -o compactador.o

descompactador.o:
	g++ descompactador.cpp $(FLAGS) -c -o descompactador.o

auxiliar_compactador.o:
	g++ auxiliar_compactador.cpp $(FLAGS) -c -o auxiliar_compactador.o

clean:
	rm -r compactar descompactar *.o