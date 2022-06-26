#include <iostream>
#include <string.h>
#include <map>
#include "grafos.h"

enum{
    PADRAO = 1,
    ALEATORIO,
    SEPARACAO,
    PALAVRAS
};

int main(){

    int escolha_inicial;
    int num_vertices;
    int num_componentes;
    int *tamanho_componentes;
    double probabilidade;
    std::vector<int> *adj;

    do{
        std::cout << "Escolha o modo de execução:\n";
        std::cout << "1) Receber grafo da entrada padrão.\n";
        std::cout << "2) Gerar grafo aleatório e testar Erdos.\n";
        std::cout << "3) Gerar grafo aleatório e testar Seis Graus de Separação.\n";
        // std::cout << "4) Gerar grafo de palavras e Testar a Distância Entre Duas Palavras.\n";
        std::cin >> escolha_inicial;
    } while(escolha_inicial > 3 || escolha_inicial <= 0);

    switch(escolha_inicial){
        case PADRAO:
            int num_arestas;
            std::cout << "Digite respectivamente o número de vértices e o número de arestas: ";
            std::cin >> num_vertices >> num_arestas;
            adj = construir_grafo_inteiros(num_vertices, num_arestas);
            tamanho_componentes = identificar_componentes(adj, num_vertices, num_componentes);
            std::cout << "Número de componentes conexas: " << num_componentes << std::endl;
            for(int i = 0 ; i < num_componentes ; i++)
                std::cout << "Tamanho da componente " << i+1 << ": " << tamanho_componentes[i] << std::endl;
            testar_separacao(adj, num_vertices);
            break;

        case ALEATORIO:
            std::cout << "Digite respectivamente o número de vértices e a probabilidade da existência de uma aresta: ";
            std::cin >> num_vertices >> probabilidade;
            adj = construir_grafo_aleatorio(num_vertices, probabilidade);
            tamanho_componentes = identificar_componentes(adj, num_vertices, num_componentes);
            testar_erdos(adj, num_vertices, probabilidade, tamanho_componentes, num_componentes);
            break;
        
        case SEPARACAO:
            std::cout << "Digite respectivamente o número de vértices e a probabilidade de duas pessoas se conhecerem: ";
            std::cin >> num_vertices >> probabilidade;
            adj = construir_grafo_aleatorio(num_vertices, probabilidade);
            testar_separacao(adj, num_vertices);
            break;

        // case PALAVRAS:
        //     std::cin >> num_vertices;
        //     std::map<std::string, int> indices_palavras;
        //     adj = construir_grafo_palavras(num_vertices, indices_palavras);
        //     break;
    };

    std::cout << "Fim de execução.\n";
}