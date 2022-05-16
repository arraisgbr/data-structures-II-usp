#pragma once

template<typename T>
class Node{
    public:
        T info;
        Node<T> *next;

    public:
        Node();

        Node(T info){
            this->info = info;
            this->next = NULL;
        }
};

template<typename T>
class PilhaLL{
    private:
        Node<T> *node;
        int currSize;
    
    public:
        PilhaLL(){
            this->node = NULL;
            this->currSize = 0;
        }

        // ~PilhaLL(){
        //     Node<T> *aux;
        //     while(this->node != NULL){
        //         aux = this->node;
        //         this->node = aux->next;
        //         delete aux;
        //     }
        // }

        void push(T elem){
            Node<T> *newNode = new Node<T>(elem);
            newNode->next = this->node;
            this->node = newNode;
            this->currSize++;
        }

        T top(){ return this->node->info; }

        void pop(){
            if(this->isEmpty()) return;
            else{
                Node<T> *oldNode = this->node;
                if(this->currSize == 1) this->node = NULL;
                else this->node = oldNode->next;
                delete oldNode;
            }
            this->currSize--;
        }

        int size(){ return this->currSize; }

        bool isEmpty(){
            if(this->node == NULL) return true;
            return false;
        }
};