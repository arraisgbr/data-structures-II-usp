#include <iostream>
#include <queue>
#include "auxiliar_compactador.h"

int main(int argc, char **argv){

    // verificando se o nome do arquivo foi informado
    #pragma region
    if(argc < 2){
        std::cout << "Nome do arquivo não informado." << std::endl;
        return 1;
    }
    #pragma endregion

    // lendo arquivo
    #pragma region
    std::string nome_arquivo = argv[1];
    std::string conteudo = "";
    ler_arquivo(nome_arquivo, &conteudo);
                // std::cout << conteudo << std::endl;
    #pragma endregion

    // montando tabela de frequencias dos caracteres
    #pragma region
    unsigned int frequencias[MAX];
    montar_frequencia(conteudo, frequencias);
                // for(int i = 0 ; i < MAX ; i++){
                //     if(frequencias[i] > 0)
                //         std::cout << "Caractere " << (char)i << ": " << frequencias[i] << std::endl;
                // }
    #pragma endregion

    // criando a fila de prioridades com as frequencias dos caracteres
    #pragma region
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> fila;
    montar_fila(fila, frequencias);
                // while(!fila.empty()){
                //     Node aux = fila.top(); fila.pop();
                //     std::cout << aux.letra << " " << aux.frequencia << std::endl;
                // }
    #pragma endregion

    // criando a arvore de huffman
    
}