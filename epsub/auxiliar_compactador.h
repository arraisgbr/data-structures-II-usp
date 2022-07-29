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