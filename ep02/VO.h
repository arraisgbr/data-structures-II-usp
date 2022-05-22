#pragma once
#include<algorithm>
#include "Tree.h"

template<typename Key, typename Item>
class VO : public Tree<Key, Item>{
    private:
        Node<Key, Item> *array;
        int size;
        int maxSize;
        
    public:
        VO(){ 
            this->array = new Node<Key, Item>[100];
            this->size = 0;
            this->maxSize = 100;
        }
        
        ~VO(){ delete[] this->array; }
        
        void add(Key key, Item value);
        Item value(Key key);
        int rank(Key key);
        Key select(int k);
        void print();
    
    private:
        int shift(Key key);
        void resize();
        int binarySearch(Key key);

};

template<typename Key, typename Item>
void VO<Key, Item>::add(Key key, Item value){
    Node<Key, Item> newNode = Node<Key, Item>(key, value);
    if(this->size == this->maxSize) resize();
    int pos = shift(key);
    if(this->size == 0){
        this->array[0] = newNode;
        this->size++;
        return;
    }
    if(this->array[pos].key == key) this->array[pos].value = value;
    else{
        this->array[pos] = newNode;
        this->size++;
    }
}

template<typename Key, typename Item>
Item VO<Key, Item>::value(Key key){
    int pos = binarySearch(key);
    return this->array[pos].value;
}

template<typename Key, typename Item>
int VO<Key, Item>::rank(Key key){
    int pos = binarySearch(key);
    return pos;
}

template<typename Key, typename Item>
Key VO<Key, Item>::select(int k){ return this->array[k].key; }

template<typename Key, typename Item>
void VO<Key, Item>::print(){
    for(int i = 0 ; i < this->size ; i++)
        std::cout << this->array[i].key << std::endl;
}

template<typename Key, typename Item>
int VO<Key, Item>::shift(Key key){
    int i = this->size - 1;
    for( ; this->array[i].key > key && i >= 0 ; i--)
        this->array[i+1] = this->array[i];
    
    return i+1;
}

template<typename Key, typename Item>
void VO<Key, Item>::resize(){
    this->maxSize = this->maxSize * 2;
    Node<Key, Item> *newArray = new Node<Key, Item>[this->maxSize];
    memcpy(newArray, this->array, sizeof(Node<Key, Item>) * this->size);
    delete[] this->array;
    this->array = newArray;
}

template<typename Key, typename Item>
int VO<Key, Item>::binarySearch(Key key){
    int l = 0;
    int r = this->size;
    while(l <= r){
        int m = (r + l) / 2;
        if(this->array[m].key == key) return m;
        else if(this->array[m].key > key) r = m-1;
        else l = m+1;
    }
}