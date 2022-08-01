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
        conteudo->replace(conteudo->end()-1, conteudo->end(), "\0");
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

void gravar_arvore(Node* raiz, std::ofstream &arquivo){
    if(raiz->letra == '+'){
        char byte = '0';
        arquivo.write(&byte, sizeof(char));
    }
    else{
        char byte = '1';
        char letra = raiz->letra;
        arquivo.write(&byte, sizeof(char));
        arquivo.write(&letra, sizeof(char));
        return;
    }
    gravar_arvore(raiz->esq, arquivo);
    gravar_arvore(raiz->dir, arquivo);
}

void criar_arquivo_bin(std::string codigo_binario, std::string nome_arquivo, Node *raiz){
    std::ofstream arquivo;
    nome_arquivo.replace(nome_arquivo.end()-4, nome_arquivo.end(), ".bin");
    arquivo.open(nome_arquivo, std::ios::binary);
    if(arquivo.is_open()){
        gravar_arvore(raiz, arquivo);
        char delimitador = '#';
        arquivo.write(&delimitador, sizeof(char));
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

Node* ler_arvore(Node* raiz, std::ifstream &arquivo){
    char byte;
    arquivo.read(&byte, sizeof(char));
    if(byte == '#') return NULL;
    else if(byte == '1'){
        char letra;
        arquivo.read(&letra, sizeof(char));
        raiz->letra = letra;
    } 
    else{
        raiz->esq = new Node('+', 0, NULL, NULL);
        raiz->dir = new Node('+', 0, NULL, NULL);
        raiz->esq = ler_arvore(raiz->esq, arquivo);
        raiz->dir = ler_arvore(raiz->dir, arquivo);
    }
    return raiz;
}

void criar_arquivo_txt(std::string nome_arquivo){
    std::ifstream arquivo_bin;
    std::ofstream arquivo_txt;
    std::string nome_arquivo_bin = nome_arquivo.replace(nome_arquivo.end()-4, nome_arquivo.end(), ".bin");
    std::string nome_arquivo_txt = nome_arquivo.replace(nome_arquivo.end()-4, nome_arquivo.end(), "2.txt");
    arquivo_bin.open(nome_arquivo_bin, std::ios::binary);
    arquivo_txt.open(nome_arquivo_txt, std::ios::binary);
    Node *raiz = new Node('+', 0, NULL, NULL);
    Node *aux = ler_arvore(raiz, arquivo_bin);
    if(arquivo_bin.is_open() && arquivo_txt.is_open()){
        char byte;
        while(arquivo_bin.read(&byte, sizeof(char))){
            for(int i = 7 ; i >= 0 ; i--){
                if(byte & (1 << i)) aux = aux->dir;
                else aux = aux->esq;
                if(aux->esq == NULL && aux->dir == NULL){
                    arquivo_txt << aux->letra;
                    aux = raiz;
                }
            }
        }
        arquivo_bin.close();
        arquivo_txt.close();
    }
    else std::cout << "Não foi possível abrir o arquivo necessário. " << std::endl;
}