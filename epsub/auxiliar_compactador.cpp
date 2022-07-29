#include <iostream>
#include <fstream>
#include "auxiliar_compactador.h"

void ler_arquivo(std::string nome_arquivo, std::string *conteudo){
    std::ifstream arquivo;
    arquivo.open(nome_arquivo);
    std::string linha;
    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            *conteudo += linha;
            *conteudo += '\n';
        }
        arquivo.close();
    }
    else std::cout << "Não foi possível abrir o arquivo." << std::endl;
}

void montar_frequencia(std::string conteudo, unsigned int *frequencias){
    for(int i = 0 ; i < MAX ; i++) frequencias[i] = 0;
    for(int i = 0 ; i < conteudo.size() ; i++) frequencias[(int)conteudo[i]]++;
}

void montar_fila(std::priority_queue<Node, std::vector<Node>, std::greater<Node>> &fila, unsigned int *frequencias){
    for(int i = 0 ; i < MAX ; i++){
        if(frequencias[i] > 0){
            fila.push({(unsigned char)i, frequencias[i], NULL, NULL});
        }
    }
}