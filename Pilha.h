#pragma once

template<typename T>
class Pilha{
    private:
        T *elem;
        int maxSize;
        int currSize;
    
    public:
        Pilha(){
            this->maxSize = 1;
            this->currSize = 0;
            this->elem = new T[maxSize];
        }

        ~Pilha(){ delete[] this->elem; }

        void push(T elem){
            if(this->currSize == this->maxSize)
                this->resize();
            this->elem[this->currSize++] = elem;
        }

        T top(){ return this->elem[this->currSize - 1]; }

        void pop(){ if(this->currSize > 0) this->currSize--; }

        int size(){ return this->currSize; }

        bool isEmpty(){ return (this->currSize == 0 ? true : false); }
    
    private:
        void resize(){
            int newSize = this->maxSize * 2;
            T *newElem = new T[newSize];
            memcpy(newElem, this->elem, currSize * sizeof(T));
            delete[] this->elem;
            this->elem = newElem;
        }
};
