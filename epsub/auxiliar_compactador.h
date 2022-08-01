#pragma once
#include <queue>
#include "node.h"

#define MAX 256

void ler_arquivo(std::string nome_arquivo, std::string *conteudo);

void montar_frequencia(std::string conteudo, unsigned int *frequencias);

void montar_fila(std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> &fila, unsigned int *frequencias);

Node* montar_arvore(std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> &fila);

void montar_dicionario(std::string *dicionario, Node *raiz, std::string codigo);

void gerar_codigo_binario(std::string conteudo, std::string *codigo_binario, std::string *dicionario);

void gravar_arvore(Node *raiz, std::ofstream &arquivo);

void criar_arquivo_bin(std::string codigo_binario, std::string nome_arquivo, Node *raiz);

Node* ler_arvore(Node* raiz, std::ifstream &arquivo);

void criar_arquivo_txt(std::string nome_arquivo);