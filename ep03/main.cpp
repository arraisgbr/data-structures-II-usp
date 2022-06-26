#include <iostream>
#include <string.h>
#include <map>
#include "grafos.h"

enum{
    PADRAO = 1,
    ALEATORIO,
    PALAVRAS
};

int main(){

    int escolha_inicial;
    int num_vertices;
    std::vector<int> *adj;

    do{
        std::cout << "Escolha o modo de execução:\n";
        std::cout << "1) Receber grafo da entrada padrão.\n";
        std::cout << "2) Gerar grafo aleatório.\n";
        std::cout << "3) Gerar grafo de palavras.\n";
        std::cin >> escolha_inicial;
    } while(escolha_inicial > 3 || escolha_inicial <= 0);

    switch(escolha_inicial){
        case PADRAO:
            int num_arestas;
            std::cout << "Digite respectivamente o número de vértices e o número de arestas: ";
            std::cin >> num_vertices >> num_arestas;
            adj = construir_grafo_inteiros(num_vertices, num_arestas);
            identificar_componentes(adj, num_vertices);
            calcular_distancias(adj, num_vertices);
            break;
        case ALEATORIO:
            int probabilidade;
            std::cout << "Digite respectivamente o número de vértices e a probabilidade da existência de uma aresta: ";
            std::cin >> num_vertices >> probabilidade;
            adj = construir_grafo_aleatorio(num_vertices, probabilidade);
            testar_erdos(adj, num_vertices);
            break;
        case PALAVRAS:
            std::cin >> num_vertices;
            std::map<std::string, int> indices_palavras;
            adj = construir_grafo_palavras(num_vertices, indices_palavras);
            identificar_componentes(adj, num_vertices);
            calcular_distancias(adj, num_vertices);
            break;
    };

    std::cout << "Fim de execução.\n";
}