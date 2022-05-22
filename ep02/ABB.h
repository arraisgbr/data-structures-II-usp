#pragma once
#include "Tree.h"

template<typename Key, typename Item>
class ABB : public Tree<Key, Item>{
    private:
        NodeS<Key, Item> *root;
    
    public:
        ABB(){ this->root = NULL; }

        void add(Key key, Item value);
        Item value(Key key);
        int rank(Key key);
        Key select(int k);
        void print();
    
    private:
        void preOrder(NodeS<Key, Item> *no);
};

template<typename Key, typename Item>
void ABB<Key, Item>::add(Key key, Item value){
    NodeS<Key, Item> *newNo = new NodeS<Key, Item>(key, value, 0);
    if(this->root == NULL){
        this->root = newNo;
        return;
    }

    NodeS<Key, Item> *ant = NULL;
    NodeS<Key, Item> *at = this->root;
    while(at != NULL){
        ant = at;
        if(at->key == key){
            at->value = value;
            return;
        }
        else if(key > at->key) at = at->right;
        else at = at->left;
    }
    
    if(key > ant->key)
        ant->right = newNo;
    else
        ant->left = newNo;
}

template<typename Key, typename Item>
Item ABB<Key, Item>::value(Key key){
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
int ABB<Key, Item>::rank(Key key){ return 1; }

template<typename Key, typename Item>
Key ABB<Key, Item>::select(int k){ return k; }

template<typename Key, typename Item>
void ABB<Key, Item>::print(){ preOrder(this->root); }

template<typename Key, typename Item>
void ABB<Key, Item>::preOrder(NodeS<Key, Item> *no){
    if(no == NULL) return;
    std::cout << no->key << std::endl;
    preOrder(no->left);
    preOrder(no->right);
}