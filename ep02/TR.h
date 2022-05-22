#pragma once
#include "Tree.h"

template<typename Key, typename Item>
class Treap : public Tree<Key, Item>{
    private:
        NodeS<Key, Item> *root;

    public:
        Treap(){ this->root = NULL; }
        void add(Key key, Item value);
        Item value(Key key);
        int rank(Key key);
        Key select(int k);
        void print();

    private:
        NodeS<Key, Item>* put(NodeS<Key, Item> *node, Key key, Item value);
        void preOrder(NodeS<Key, Item> *no);
        int isOk(NodeS<Key, Item> *node);
        NodeS<Key, Item>* left(NodeS<Key, Item> *node);
        NodeS<Key, Item>* right(NodeS<Key, Item> *node);
};

template<typename Key, typename Item>
void Treap<Key, Item>::add(Key key, Item value){ this->root = put(this->root, key, value); }

template<typename Key, typename Item>
Item Treap<Key, Item>::value(Key key){
    if(this->root == NULL) return NULL;
    if(this->root->key == key) return this->root->value;
    NodeS<Key, Item> *aux = this->root;

    while(aux != NULL){
        if(key == aux->key) return aux->value;
        else if(key > aux->key) aux = aux->right;
        else aux = aux->left;
    }
}

template<typename Key, typename Item>
int Treap<Key, Item>::rank(Key key){
    return 1;
}

template<typename Key, typename Item>
Key Treap<Key, Item>::select(int k){
    return 1;
}

template<typename Key, typename Item>
void Treap<Key, Item>::print(){ preOrder(this->root); }

template<typename Key, typename Item>
NodeS<Key, Item>* Treap<Key, Item>::put(NodeS<Key, Item> *node, Key key, Item value){
    if(node == NULL){
        int priority = rand();
        node = new NodeS<Key, Item>(key, value, priority);
        return node;
    }
    
    if(key == node->key) node->value = value;
    else if(key > node->key) node->right = put(node->right, key, value);
    else node->left = put(node->left, key, value);
    
    if(isOk(node) == -1) node = right(node);
    else if(isOk(node) == 1) node = left(node);

    return node;
} 

template<typename Key, typename Item>
void Treap<Key, Item>::preOrder(NodeS<Key, Item> *no){
    if(no == NULL) return;
    std::cout << no->key << std::endl;
    preOrder(no->left);
    preOrder(no->right);
}

template<typename Key, typename Item>
int Treap<Key, Item>::isOk(NodeS<Key, Item> *no){
    if(no->left != NULL && no->left->priority > no->priority) return -1;
    if(no->right != NULL && no->right->priority > no->priority) return 1;
    return 0;
}

template<typename Key, typename Item>
NodeS<Key, Item>* Treap<Key, Item>::left(NodeS<Key, Item> *no){
    NodeS<Key, Item> *aux = no->right;
    no->right = aux->left;
    aux->left = no;
    return aux;
}

template<typename Key, typename Item>
NodeS<Key, Item>* Treap<Key, Item>::right(NodeS<Key, Item> *no){
    NodeS<Key, Item> *aux = no->left;
    no->left = aux->right;
    aux->right = no;
    return aux;
}
