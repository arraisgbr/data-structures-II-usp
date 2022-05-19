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
            this->array = new Node<Key, Item>[2];
            this->size = 0;
            this->maxSize = 2;
        }
        
        ~VO(){ delete[] this->array; }
        
        void add(Key key, Item value){
            Node<Key, Item> newNode = Node<Key, Item>(key, value);
            if(this->size == this->maxSize) resize();
            if(this->size == 0){
                this->array[0] = newNode;
                this->size++;
                return;
            }
            int pos = binarySearch(key);
            if(this->array[pos - 1].key == key){
                this->array[pos - 1].value = value;
                return;
            }
            shift(pos);
            this->array[pos] = newNode;
            this->size++;
        }

        Item value(Key key){
            int pos = binarySearch(key) - 1;
            return this->array[pos].value;
        }

        int rank(Key key){
            int pos = binarySearch(key) - 1;
            return pos;
        }

        Key select(int k){ return this->array[k].key; }
    
    private:
        int binarySearch(Key key){
            int l = 0;
            int r = this->size;
            int pos;
            while(l < r){
                int m = (l + r) / 2;
                if(this->array[m].key <= key){
                    l = m + 1;
                }
                else r = m;
            }

            if(l < this->size && this->array[l].key <= key) l++;
            return l;
        }

        void shift(int first){
            for(int i = this->size ; i >= first ; i--)
                this->array[i+1] = this->array[i];
        }

        void resize(){
            this->maxSize = this->maxSize * 2;
            Node<Key, Item> *newArray = new Node<Key, Item>[this->maxSize];
            memcpy(newArray, this->array, sizeof(Node<Key, Item>) * this->size);
            delete[] this->array;
            this->array = newArray;
        }
};