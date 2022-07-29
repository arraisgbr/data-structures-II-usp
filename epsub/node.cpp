#include "node.h"

Node::Node(unsigned char letra, unsigned int frequencia, Node *esq, Node *dir){
    this->letra = letra;
    this->frequencia = frequencia;
    this->esq = esq;
    this->dir = dir;
}

bool Node::operator>(const Node &a) const{
    return this->frequencia > a.frequencia;
}