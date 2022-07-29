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
    #pragma endregion

    // criando tabela de frequencias dos caracteres
    #pragma region
    unsigned int frequencias[MAX];
    montar_frequencia(conteudo, frequencias);
    #pragma endregion

    // criando a fila de prioridades com as frequencias dos caracteres
    #pragma region
    std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> fila;
    montar_fila(fila, frequencias);
    // while(!fila.empty()){
    //     Node *topo = fila.top(); fila.pop();
    //     std::cout << "Caractere: " << topo->letra << " | Frequencia: " << topo->frequencia << std::endl;
    // }
    #pragma endregion

    // criando a arvore de huffman
    #pragma region
    Node *raiz = montar_arvore(fila);
    #pragma endregion

    // criando dicionario
    #pragma region
    std::string dicionario[MAX];
    std::string codigo = "";
    montar_dicionario(dicionario, raiz, codigo);
    // for(int i = 0 ; i < MAX ; i++){
    //     if(dicionario[i].size() > 0) std::cout << "Caractere: " << (unsigned char)i << " | Código: " << dicionario[i] << std::endl;
    // }
    #pragma endregion
}