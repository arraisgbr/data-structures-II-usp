#pragma once

#include <vector>
#include <utility>

#define mp std::make_pair

class Pentamino{
    public:
        char letter;
        int numVariations;
        std::pair<int,int> **pos;

    public:
        Pentamino(char letter, int numVariations, std::pair<int, int> **pos){
            this->letter = letter;
            this->numVariations = numVariations;
            this->pos = new std::pair<int, int>*[numVariations];
            for(int i = 0 ; i < this->numVariations ; i++){
                this->pos[i] = new std::pair<int,int>[4];
                this->pos[i] = pos[i];
            }
        }
};

// toDo
Pentamino* build_F(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;    
}

Pentamino* build_I(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

// toDo
Pentamino* build_L(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

// toDo
Pentamino* build_N(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

// toDo
Pentamino* build_P(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

// toDo
Pentamino* build_T(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

// toDo
Pentamino* build_U(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

// toDo
Pentamino* build_V(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

// toDo
Pentamino* build_W(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

Pentamino* build_X(){
    std::pair<int,int> **pos = new std::pair<int, int>*[1];
    pos[0] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(1, -1); pos[0][3] = mp(1, 1);

    Pentamino *penta = new Pentamino('I', 1, pos);

    return penta;
}

// toDo
Pentamino* build_Y(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}

// toDo
Pentamino* build_Z(){
    std::pair<int,int> **pos = new std::pair<int, int>*[2];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(4, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(0, 2); pos[1][2] = mp(0, 3); pos[1][3] = mp(0, 4);

    Pentamino *penta = new Pentamino('I', 2, pos);

    return penta;
}