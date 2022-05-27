#pragma once
#include "HT.h"

template<typename Key, typename Item>
class ARN : public HT<Key, Item>{
    private:
        NodeRB<Key, Item> *root;

    public:
        ARN(){ this->root = NULL; }
        
        void add(Key key, Item value);
        Item value(Key key);
        int rank(Key key);
        Key select(int k);
        void print();
        void preOrder(NodeRB<Key, Item> *node);
    
    private:
        void isOk(NodeRB<Key, Item> *node);
        NodeRB<Key, Item>* left(NodeRB<Key, Item> *node);
        NodeRB<Key, Item>* right(NodeRB<Key, Item> *node);
};

template<typename Key, typename Item>
void ARN<Key, Item>::add(Key key, Item value){
    
    if(this->root == NULL){
        NodeRB<Key, Item> *newNode = new NodeRB<Key, Item>(key, value, NULL, black);
        this->root = newNode;
        return;
    }

    NodeRB<Key, Item> *at = this->root;
    bool found = false;
    while(!found) {
        if(key < at->key) {
            if(at->left != NULL){
                at->leftsize++;
                at = at->left;
            }
            else found = true;
        }
        else if(key > at->key) {
            if(at->right != NULL){
                at->rightsize++;
                at = at->right;
            }
            else found = true;
        }
        else found = true;
    }

    bool grow = true;
    if(at->key == key) {
        grow = false;
        at->value += value;
        return;
    }

    if(!grow){
        NodeRB<Key, Item> *aux = this->root;
        while(aux != NULL){
            if(aux->key == key) return;
            else if(key > aux->key){
                aux->rightsize--;
                aux = aux->right;
            }
            else if(key < aux->key){
                aux->leftsize--;
                aux = aux->left;
            }
        }
    }

    NodeRB<Key, Item> *newNode = new NodeRB<Key, Item>(key, value, at, red);
    if(key > at->key)
        at->right = newNode;
    else 
        at->left = newNode;

    isOk(newNode);
}

template<typename Key, typename Item>
Item ARN<Key, Item>::value(Key key){
    if(this->root == NULL) return NULL;
    NodeRB<Key, Item> *aux = this->root;
    while(aux != NULL){
        if(aux->key == key) return aux->value;
        else if(key > aux->key) aux = aux->right;
        else aux = aux->left;
    }
}

template<typename Key, typename Item>
int ARN<Key, Item>::rank(Key key){
    NodeRB<Key, Item> *aux = this->root;
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
Key ARN<Key, Item>::select(int k){
    NodeRB<Key, Item> *aux = this->root;

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
void ARN<Key, Item>::print(){
    preOrder(this->root);
}  

template<typename Key, typename Item>
void ARN<Key, Item>::preOrder(NodeRB<Key, Item> *node){
    if(node == NULL) return;
    std::cout << node->value << " ";
    if(node->color) std::cout << "red" << std::endl;
    else std::cout << "black" << std::endl;
    preOrder(node->left);
    preOrder(node->right);
}

template<typename Key, typename Item>
void ARN<Key, Item>::isOk(NodeRB<Key, Item> *node){
    NodeRB<Key, Item> *verifyingNode = node;
    // while verifyingNode is not okay, do the rotations
    while(true){
        NodeRB<Key, Item> *father = verifyingNode->father;

        // if father is null verifying node is the root        
        if(father == NULL){
            verifyingNode->color = black;
            return;
        }

        if(father->left != NULL)
            father->leftsize = father->left->leftsize + father->left->rightsize + 1;
        if(father->right != NULL)
            father->rightsize = father->right->leftsize + father->right->rightsize + 1;

        if(father->color == black) return;
        
        NodeRB<Key, Item> *grandfather = father->father;
        // if grandfather is null father of verifying node is root
        if(grandfather == NULL){
            father->color = black;
            return;
        }

        // if the father is a left child
        if(grandfather->left == father){
            NodeRB<Key, Item> *uncle = grandfather->right;
            // if the uncle is red
            if(uncle != NULL && uncle->color == red){
                verifyingNode = grandfather;
                grandfather->color = red;
                father->color = uncle->color = black;
            }
            else{
                // if the node is a right child of a left father
                if(father->right != NULL && father->right == verifyingNode)
                    grandfather->left = left(father);

                grandfather->color = red;
                verifyingNode->color = black;
                verifyingNode->father->left = right(grandfather);
            }
        }
        else{
            NodeRB<Key, Item> *uncle = grandfather->left;
            // if the uncle is red
            if(uncle != NULL && uncle->color == red){
                verifyingNode = grandfather;
                grandfather->color = red;
                father->color = uncle->color = black;
            }
            else{
                // if the node is a left child of a right father
                if(father->left != NULL && father->left == verifyingNode)
                    grandfather->right = right(father);

                grandfather->color = red;
                verifyingNode->color = black;
                verifyingNode->father->right = left(grandfather);
            }
        }
    }
}

template<typename Key, typename Item>
NodeRB<Key, Item>* ARN<Key, Item>::left(NodeRB<Key, Item> *node){
    NodeRB<Key, Item> *aux = node->right;
    node->right = aux->left;
    aux->left = node;

    aux->father = node->father;
    node->father = aux;
    if(node->right != NULL)
        node->right->father = node;


    // leftsizes and rightsizes
    aux->leftsize = 0;
    node->rightsize = 0;
    if(aux->left != NULL) aux->leftsize += aux->left->leftsize + aux->left->rightsize + 1;
    if(node->right != NULL) node->rightsize += node->right->leftsize + node->right->rightsize + 1; 

    return aux;
}

template<typename Key, typename Item>
NodeRB<Key, Item>* ARN<Key, Item>::right(NodeRB<Key, Item> *node){
    NodeRB<Key, Item> *aux = node->left;
    node->left = aux->right;
    aux->right = node;

    aux->father = node->father;
    node->father = aux;
    if(node->left != NULL)
        node->left->father = node;

    // leftsizes and rightsizes
    node->leftsize = 0;
    aux->rightsize = 0;
    if(node->left != NULL) node->leftsize += node->left->leftsize + node->left->rightsize + 1;
    if(aux->right != NULL) aux->rightsize += aux->right->leftsize + aux->right->rightsize + 1;

    return aux;
}