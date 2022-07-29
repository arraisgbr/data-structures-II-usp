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

void montar_fila(std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> &fila, unsigned int *frequencias){
    for(int i = 0 ; i < MAX ; i++){
        if(frequencias[i] > 0){
            Node *novo = new Node((unsigned char)i, frequencias[i], NULL, NULL);
            fila.push(novo);
        }
    }
}

Node* montar_arvore(std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> &fila){
    while(fila.size() > 1){
        Node *a = fila.top(); fila.pop();
        Node *b = fila.top(); fila.pop();
        Node *novo = new Node('+', a->frequencia + b->frequencia, a, b);
        fila.push(novo);
    }
    Node *raiz = fila.top(); fila.pop();
    return raiz;
}

void montar_dicionario(std::string *dicionario, Node *raiz, std::string codigo){
    if(raiz->dir == NULL && raiz->esq == NULL){
        dicionario[(int)raiz->letra] = codigo;
        return;
    }
    std::string codigo_esq = codigo + '0';
    std::string codigo_dir = codigo + '1';
    montar_dicionario(dicionario, raiz->esq, codigo_esq);
    montar_dicionario(dicionario, raiz->dir, codigo_dir);
}