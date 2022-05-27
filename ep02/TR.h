#pragma once
#include "HT.h"

template<typename Key, typename Item>
class TR : public HT<Key, Item>{
    private:
        NodeS<Key, Item> *root;

    public:
        TR(){ this->root = NULL; }
        void add(Key key, Item value);
        Item value(Key key);
        int rank(Key key);
        Key select(int k);
        void print();

    private:
        NodeS<Key, Item>* put(NodeS<Key, Item> *node, Key key, Item value, bool *grow);
        void preOrder(NodeS<Key, Item> *no);
        int isOk(NodeS<Key, Item> *node);
        NodeS<Key, Item>* left(NodeS<Key, Item> *node);
        NodeS<Key, Item>* right(NodeS<Key, Item> *node);
};

template<typename Key, typename Item>
void TR<Key, Item>::add(Key key, Item value){
    bool grow = true; 
    this->root = put(this->root, key, value, &grow);
    
    // corrigindo tamanhos
    if(grow == false){
        NodeS<Key, Item> *aux = this->root;
        while(aux != NULL){
            if(aux->key == key) break;
            else if(key > aux->key){
                aux->rightsize--;
                aux = aux->right;
            }
            else{
                aux->leftsize--;
                aux = aux->left;
            }
        }
    }
}

template<typename Key, typename Item>
Item TR<Key, Item>::value(Key key){
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
int TR<Key, Item>::rank(Key key){
    NodeS<Key, Item> *aux = this->root;
    int ans = 0;
    while(aux != NULL){
        if(aux->key == key){
            ans += aux->leftsize;
            return ans;
        }
        else if(key > aux->key){
            ans += aux->leftsize + 1;
            aux = aux->right;
        }
        else aux = aux->left;
    }
}

template<typename Key, typename Item>
Key TR<Key, Item>::select(int k){
    NodeS<Key, Item> *aux = this->root;

    while(aux != NULL){
        if(aux->leftsize == k) return aux->key;
        else if(k < aux->leftsize) aux = aux->left;
        else {
            k -= aux->leftsize + 1;
            aux = aux->right;
        }
    }

    return -1;
}

template<typename Key, typename Item>
void TR<Key, Item>::print(){ preOrder(this->root); }

template<typename Key, typename Item>
NodeS<Key, Item>* TR<Key, Item>::put(NodeS<Key, Item> *node, Key key, Item value, bool *grow){
    if(node == NULL){
        int priority = rand();
        node = new NodeS<Key, Item>(key, value, priority);
        return node;
    }
    
    if(key == node->key){
        node->value += value;
        *grow = false;
    }
    else if(key > node->key){
        node->rightsize++;
        node->right = put(node->right, key, value, grow);
    }
    else{
        node->leftsize++;
        node->left = put(node->left, key, value, grow);
    }
    if(isOk(node) == -1){
        node = right(node);
        node->leftsize = 0;
        node->rightsize = 0;
        if(node->left != NULL) node->leftsize = node->left->leftsize + node->left->rightsize + 1;
        if(node->right != NULL) node->rightsize = node->right->leftsize + node->right->leftsize + 1;
    }
    else if(isOk(node) == 1){
        node = left(node);
        node->leftsize = 0;
        node->rightsize = 0;
        if(node->left != NULL) node->leftsize = node->left->leftsize + node->left->rightsize + 1;
        if(node->right != NULL) node->rightsize = node->right->leftsize + node->right->leftsize + 1;
    }

    return node;
} 

template<typename Key, typename Item>
void TR<Key, Item>::preOrder(NodeS<Key, Item> *no){
    if(no == NULL) return;
    std::cout << no->key << std::endl;
    preOrder(no->left);
    preOrder(no->right);
}

template<typename Key, typename Item>
int TR<Key, Item>::isOk(NodeS<Key, Item> *no){
    if(no->left != NULL && no->left->priority > no->priority) return -1;
    if(no->right != NULL && no->right->priority > no->priority) return 1;
    return 0;
}

template<typename Key, typename Item>
NodeS<Key, Item>* TR<Key, Item>::left(NodeS<Key, Item> *no){
    NodeS<Key, Item> *aux = no->right;
    no->right = aux->left;
    aux->left = no;

    // leftsizes and rightsizes
    aux->leftsize = 0;
    no->rightsize = 0;
    if(aux->left != NULL) aux->leftsize += aux->left->leftsize + aux->left->rightsize + 1;
    if(no->right != NULL) no->rightsize += no->right->leftsize + no->right->rightsize + 1; 
    return aux;
}

template<typename Key, typename Item>
NodeS<Key, Item>* TR<Key, Item>::right(NodeS<Key, Item> *no){
    NodeS<Key, Item> *aux = no->left;
    no->left = aux->right;
    aux->right = no;
    
    // leftsizes and rightsizes
    no->leftsize = 0;
    aux->rightsize = 0;
    if(no->left != NULL) no->leftsize += no->left->leftsize + no->left->rightsize + 1;
    if(aux->right != NULL) aux->rightsize += aux->right->leftsize + aux->right->rightsize + 1;

    return aux;
}
