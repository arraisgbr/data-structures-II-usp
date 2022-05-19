#pragma once
#include "Node.h"

template<typename Key, typename Item>
class Tree{
    protected:
        virtual void add(Key key, Item value) = 0;
        virtual Item value(Key key) = 0;
        virtual int rank(Key key) = 0;
        virtual Key select(int k) = 0;
};