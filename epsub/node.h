#pragma once

class Node{
    public:
        unsigned char letra;
        unsigned int frequencia;
        Node *esq, *dir;

    public:
        Node(unsigned char letra, unsigned int frequencia, Node *esq, Node *dir);
        bool operator>(const Node &a) const;
};
