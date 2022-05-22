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
        COLOR cor;
        NodeRB *father, *grandfather;
        NodeRB *left, *right;
};

template<typename Key, typename Item>
class Node23 : public Node<Key, Item>{
    public:
        bool full;
        Node23 *pai;
        Node23 *left, *mid, *right;
};
