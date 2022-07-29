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
    for(int i = 0 ; i < conteudo.size() ; i++) frequencias[(unsigned int)conteudo[i]]++;
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
        dicionario[(unsigned int)raiz->letra] = codigo;
        return;
    }
    std::string codigo_esq = codigo + '0';
    std::string codigo_dir = codigo + '1';
    montar_dicionario(dicionario, raiz->esq, codigo_esq);
    montar_dicionario(dicionario, raiz->dir, codigo_dir);
}

void gerar_codigo_binario(std::string conteudo, std::string *codigo_binario, std::string *dicionario){
    for(int i = 0 ; i < conteudo.size() ; i++){
        *codigo_binario += dicionario[(unsigned int)conteudo[i]];
    }
}

void criar_arquivo_bin(std::string codigo_binario, std::string nome_arquivo){
    std::ofstream arquivo;
    nome_arquivo.replace(nome_arquivo.end()-4, nome_arquivo.end(), ".bin");
    arquivo.open(nome_arquivo, std::ios::binary);
    if(arquivo.is_open()){
        char byte = 0;
        int j = 7;
        for(int i = 0 ; i < codigo_binario.size() ; i++){
            if(codigo_binario[i] == '1')
                byte = byte | (1 << j);
            j--;
            if(j < 0){
                arquivo.write(&byte, sizeof(char));
                byte = 0;
                j = 7;
            }
        }
        if(j != 7) arquivo.write(&byte, sizeof(char));
        arquivo.close();
    }
    else std::cout << "Não foi possível criar o arquivo .bin." << std::endl;
}

void criar_arquivo_txt(Node *raiz, std::string nome_arquivo){
    std::ifstream arquivo;
    Node *aux = raiz;
    arquivo.open(nome_arquivo, std::ios::binary);
    if(arquivo.is_open()){
        char byte;
        while(arquivo.read(&byte, sizeof(char))){
            for(int i = 7 ; i >= 0 ; i--){
                if(byte & (1 << i)) aux = aux->dir;
                else aux = aux->esq;
                if(aux->esq == NULL && aux->dir == NULL){
                    std::cout << aux->letra;
                    aux = raiz;
                }
            }
        }
    }
}