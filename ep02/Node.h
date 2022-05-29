#pragma once

enum COLOR{
    black,
    red
};

template<typename Key, typename Item>
class Node{
    public:
        Key key;
        Item value;
        int leftsize;
        int rightsize;
    
    public:
        Node(){}
        Node(Key key, Item value){
            this->key = key;
            this->value = value;
            this->leftsize = 0;
            this->rightsize = 0;
        }
};

template<typename Key, typename Item>
class NodeS : public Node<Key, Item>{
    public:
        int priority;
        NodeS *left, *right;

    public:
        NodeS(){}
        NodeS(Key key, Item value, int priority):Node<Key, Item>(key, value){
            this->priority = priority;
            this->left = NULL;
            this->right = NULL;
        }
};

template<typename Key, typename Item>
class NodeRB : public Node<Key, Item>{
    public:
        COLOR color;
        NodeRB *father;
        NodeRB *left, *right;

    public:
        NodeRB(){}
        NodeRB(Key key, Item value, NodeRB<Key, Item> *father, COLOR color):Node<Key, Item>(key, value){
            this->father = father;
            this->color = color;
            this->left = NULL;
            this->right = NULL;
        }
};