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
    
    public:
        Node(){}
        Node(Key key, Item value){
            this->key = key;
            this->value = value;
        }
};

template<typename Key, typename Item>
class NodeS : public Node<Key, Item>{
    public:
        NodeS *left, *right;

    public:
        NodeS(){}
        NodeS(Key key, Item value){
            super(key, value);
            this->left = NULL;
            this->rigth = NULL;
        }
};

template<typename Key, typename Item>
class NodeRB : public Node<Key, Item>{
    public:
        COLOR cor;
        NodeRB *left, *pai, *right;
};

template<typename Key, typename Item>
class Node23 : public Node<Key, Item>{
    public:
        bool full;
        Node23 *left, *pai, *right;
};
