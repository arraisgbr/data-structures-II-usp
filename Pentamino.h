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
        Pentamino(){}

        Pentamino(char letter, int numVariations, std::pair<int, int> **pos){
            this->letter = letter;
            this->numVariations = numVariations;
            this->pos = new std::pair<int, int>*[numVariations];
            for(int i = 0 ; i < this->numVariations ; i++){
                this->pos[i] = new std::pair<int,int>[4];
                this->pos[i] = pos[i];
            }
        }
        
        ~Pentamino(){
        }
};

Pentamino* build_F(){
    std::pair<int,int> **pos = new std::pair<int, int>*[8];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[4] = new std::pair<int, int>[4];
    pos[5] = new std::pair<int, int>[4];
    pos[6] = new std::pair<int, int>[4];
    pos[7] = new std::pair<int, int>[4];
    pos[0][0] = mp(0, 1); pos[0][1] = mp(1, -1); pos[0][2] = mp(1, 0); pos[0][3] = mp(2, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(1, 1); pos[1][2] = mp(1, 2); pos[1][3] = mp(2, 1);
    pos[2][0] = mp(1, 0); pos[2][1] = mp(1, 1); pos[2][2] = mp(1, 2); pos[2][3] = mp(2, 1);
    pos[3][0] = mp(1, -1); pos[3][1] = mp(1, 0); pos[3][2] = mp(1, 1); pos[3][3] = mp(2, -1);
    pos[4][0] = mp(1, -1); pos[4][1] = mp(1, 0); pos[4][2] = mp(2, 0); pos[4][3] = mp(2, 1);
    pos[5][0] = mp(1, 0); pos[5][1] = mp(1, 1); pos[5][2] = mp(2, -1); pos[5][3] = mp(2, 0);
    pos[6][0] = mp(1, -1); pos[6][1] = mp(1, 0); pos[6][2] = mp(1, 1); pos[6][3] = mp(2, 1);
    pos[7][0] = mp(1, -2); pos[7][1] = mp(1, -1); pos[7][2] = mp(1, 0); pos[7][3] = mp(2, -1);

    Pentamino *penta = new Pentamino('F', 8, pos);

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

Pentamino* build_L(){
    std::pair<int,int> **pos = new std::pair<int, int>*[8];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[4] = new std::pair<int, int>[4];
    pos[5] = new std::pair<int, int>[4];
    pos[6] = new std::pair<int, int>[4];
    pos[7] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(3, 0); pos[0][3] = mp(3, 1);
    pos[1][0] = mp(1, 0); pos[1][1] = mp(2, 0); pos[1][2] = mp(3, 0); pos[1][3] = mp(3, -1);
    pos[2][0] = mp(1, -3); pos[2][1] = mp(1, -2); pos[2][2] = mp(1, -1); pos[2][3] = mp(1, 0);
    pos[3][0] = mp(0, 1); pos[3][1] = mp(0, 2); pos[3][2] = mp(0, 3); pos[3][3] = mp(1, 3);
    pos[4][0] = mp(0, 1); pos[4][1] = mp(1, 0); pos[4][2] = mp(2, 0); pos[4][3] = mp(3, 0);
    pos[5][0] = mp(0, 1); pos[5][1] = mp(1, 1); pos[5][2] = mp(2, 1); pos[5][3] = mp(3, 1);
    pos[6][0] = mp(0, 1); pos[7][1] = mp(0, 2); pos[7][2] = mp(0, 3); pos[7][3] = mp(1, 0);
    pos[7][0] = mp(1, 0); pos[6][1] = mp(1, 1); pos[6][2] = mp(1, 2); pos[6][3] = mp(1, 3);

    Pentamino *penta = new Pentamino('L', 8, pos);

    return penta;
}

Pentamino* build_N(){
    std::pair<int,int> **pos = new std::pair<int, int>*[8];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[4] = new std::pair<int, int>[4];
    pos[5] = new std::pair<int, int>[4];
    pos[6] = new std::pair<int, int>[4];
    pos[7] = new std::pair<int, int>[4];
    pos[0][0] = mp(0, 1); pos[0][1] = mp(1, 1); pos[0][2] = mp(1, 2); pos[0][3] = mp(1, 3);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(1, -2); pos[1][2] = mp(1, -1); pos[1][3] = mp(1, 0);
    pos[2][0] = mp(1, 0); pos[2][1] = mp(2, 0); pos[2][2] = mp(2, -1); pos[2][3] = mp(3, -1);
    pos[3][0] = mp(1, 0); pos[3][1] = mp(1, 1); pos[3][2] = mp(2, 1); pos[3][3] = mp(2, 2);
    pos[4][0] = mp(0, 1); pos[4][1] = mp(0, 2); pos[4][2] = mp(1, -1); pos[4][3] = mp(1, 0);
    pos[5][0] = mp(0, 1); pos[5][1] = mp(0, 2); pos[5][2] = mp(1, 2); pos[5][3] = mp(1, 3);
    pos[6][0] = mp(1, 0); pos[6][1] = mp(1, -1); pos[6][2] = mp(2, -1); pos[6][3] = mp(3, -1);
    pos[7][0] = mp(1, 0); pos[7][1] = mp(2, 0); pos[7][2] = mp(2, 1); pos[7][3] = mp(3, 1);

    Pentamino *penta = new Pentamino('N', 8, pos);

    return penta;
}

Pentamino* build_P(){
    std::pair<int,int> **pos = new std::pair<int, int>*[8];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[4] = new std::pair<int, int>[4];
    pos[5] = new std::pair<int, int>[4];
    pos[6] = new std::pair<int, int>[4];
    pos[7] = new std::pair<int, int>[4];
    pos[0][0] = mp(0, 1); pos[0][1] = mp(1, 0); pos[0][2] = mp(1, 1); pos[0][3] = mp(2, 0);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(1, 0); pos[1][2] = mp(1, 1); pos[1][3] = mp(2, 0);
    pos[2][0] = mp(0, 1); pos[2][1] = mp(1, 0); pos[2][2] = mp(1, 1); pos[2][3] = mp(1, 2);
    pos[3][0] = mp(0, 1); pos[3][1] = mp(0, 2); pos[3][2] = mp(1, 0); pos[3][3] = mp(1, 1);
    pos[4][0] = mp(1, 0); pos[4][1] = mp(1, 1); pos[4][2] = mp(2, 0); pos[4][3] = mp(2, 1);
    pos[5][0] = mp(1, -1); pos[5][1] = mp(1, 0); pos[5][2] = mp(2, -1); pos[5][3] = mp(2, 0);
    pos[6][0] = mp(0, 1); pos[6][1] = mp(0, 2); pos[6][2] = mp(1, 1); pos[6][3] = mp(1, 2);
    pos[7][0] = mp(0, 1); pos[7][1] = mp(1, -1); pos[7][2] = mp(1, 0); pos[7][3] = mp(1, 1);

    Pentamino *penta = new Pentamino('P', 8, pos);

    return penta;
}

Pentamino* build_T(){
    std::pair<int,int> **pos = new std::pair<int, int>*[4];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[0][0] = mp(0, 1); pos[0][1] = mp(0, 2); pos[0][2] = mp(1, 1); pos[0][3] = mp(2, 1);
    pos[1][0] = mp(1, 0); pos[1][1] = mp(1, 1); pos[1][2] = mp(1, 2); pos[1][3] = mp(2, 0);
    pos[2][0] = mp(1, 0); pos[2][1] = mp(2, -1); pos[2][2] = mp(2, 0); pos[2][3] = mp(2, 1);
    pos[3][0] = mp(1, -2); pos[3][1] = mp(1, -1); pos[3][2] = mp(1, 0); pos[3][3] = mp(2, 0);
    
    Pentamino *penta = new Pentamino('T', 4, pos);

    return penta;
}

Pentamino* build_U(){
    std::pair<int,int> **pos = new std::pair<int, int>*[4];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[0][0] = mp(0, 2); pos[0][1] = mp(1, 0); pos[0][2] = mp(1, 1); pos[0][3] = mp(1, 2);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(1, 1); pos[1][2] = mp(1, 0); pos[1][3] = mp(2, 1);
    pos[2][0] = mp(0, 1); pos[2][1] = mp(0, 2); pos[2][2] = mp(1, 0); pos[2][3] = mp(1, 2);
    pos[3][0] = mp(0, 1); pos[3][1] = mp(1, 0); pos[3][2] = mp(2, 0); pos[3][3] = mp(2, 1);

    Pentamino *penta = new Pentamino('U', 4, pos);

    return penta;
}

Pentamino* build_V(){
    std::pair<int,int> **pos = new std::pair<int, int>*[8];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[4] = new std::pair<int, int>[4];
    pos[5] = new std::pair<int, int>[4];
    pos[6] = new std::pair<int, int>[4];
    pos[7] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(2, 0); pos[0][2] = mp(2, 1); pos[0][3] = mp(2, 2);
    pos[1][0] = mp(1, 0); pos[1][1] = mp(2, -2); pos[1][2] = mp(2, -1); pos[1][3] = mp(2, 0);
    pos[2][0] = mp(1, 0); pos[2][1] = mp(2, -2); pos[2][2] = mp(2, -1); pos[2][3] = mp(2, 0);
    pos[3][0] = mp(0, 1); pos[3][1] = mp(0, 2); pos[3][2] = mp(1, 2); pos[3][3] = mp(2, 2);
    pos[4][0] = mp(0, 1); pos[4][1] = mp(0, 2); pos[4][2] = mp(1, 0); pos[4][3] = mp(2, 0);
    pos[5][0] = mp(0, 1); pos[5][1] = mp(0, 2); pos[5][2] = mp(1, 2); pos[5][3] = mp(2, 2);
    pos[6][0] = mp(0, 1); pos[6][1] = mp(0, 2); pos[6][2] = mp(1, 0); pos[6][3] = mp(2, 0);
    pos[7][0] = mp(1, 0); pos[7][1] = mp(2, 0); pos[7][2] = mp(2, 1); pos[7][3] = mp(2, 2);

    Pentamino *penta = new Pentamino('V', 8, pos);

    return penta;
}

Pentamino* build_W(){
    std::pair<int,int> **pos = new std::pair<int, int>*[8];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[4] = new std::pair<int, int>[4];
    pos[5] = new std::pair<int, int>[4];
    pos[6] = new std::pair<int, int>[4];
    pos[7] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, 0); pos[0][1] = mp(1, 1); pos[0][2] = mp(2, 1); pos[0][3] = mp(2, 2);
    pos[1][0] = mp(1, -1); pos[1][1] = mp(1, 0); pos[1][2] = mp(2, -2); pos[1][3] = mp(2, -1);
    pos[2][0] = mp(0, 1); pos[2][1] = mp(1, 1); pos[2][2] = mp(1, 2); pos[2][3] = mp(2, 2);
    pos[3][0] = mp(1, -1); pos[3][1] = mp(1, 0); pos[3][2] = mp(2, -2); pos[3][3] = mp(2, -1);
    pos[4][0] = mp(0, 1); pos[4][1] = mp(1, -1); pos[4][2] = mp(1, 0); pos[4][3] = mp(2, -1);
    pos[5][0] = mp(0, 1); pos[5][1] = mp(1, 1); pos[5][2] = mp(1, 2); pos[5][3] = mp(2, 2);
    pos[6][0] = mp(0, 1); pos[6][1] = mp(1, 0); pos[6][2] = mp(1, -1); pos[6][3] = mp(2, -1);
    pos[7][0] = mp(1, 0); pos[7][1] = mp(1, 1); pos[7][2] = mp(2, 1); pos[7][3] = mp(2, 2);

    Pentamino *penta = new Pentamino('W', 8, pos);

    return penta;
}

Pentamino* build_X(){
    std::pair<int,int> **pos = new std::pair<int, int>*[1];
    pos[0] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, -1); pos[0][1] = mp(1, 0); pos[0][2] = mp(1, 1); pos[0][3] = mp(2, 0);

    Pentamino *penta = new Pentamino('X', 1, pos);

    return penta;
}

Pentamino* build_Y(){
    std::pair<int,int> **pos = new std::pair<int, int>*[8];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[4] = new std::pair<int, int>[4];
    pos[5] = new std::pair<int, int>[4];
    pos[6] = new std::pair<int, int>[4];
    pos[7] = new std::pair<int, int>[4];
    pos[0][0] = mp(1, -2); pos[0][1] = mp(1, -1); pos[0][2] = mp(1, 0); pos[0][3] = mp(1, 1);
    pos[1][0] = mp(1, -1); pos[1][1] = mp(1, 0); pos[1][2] = mp(1, 1); pos[1][3] = mp(1, 2);
    pos[2][0] = mp(1, 0); pos[2][1] = mp(2, -1); pos[2][2] = mp(2, 0); pos[2][3] = mp(3, 0);
    pos[3][0] = mp(1, 0); pos[3][1] = mp(1, -1); pos[3][2] = mp(2, 0); pos[3][3] = mp(3, 0);
    pos[4][0] = mp(0, 1); pos[4][1] = mp(0, 2); pos[4][2] = mp(0, 3); pos[4][3] = mp(1, 2);
    pos[5][0] = mp(0, 1); pos[5][1] = mp(0, 2); pos[5][2] = mp(0, 3); pos[5][3] = mp(1, 1);
    pos[6][0] = mp(1, 0); pos[6][1] = mp(2, 0); pos[6][2] = mp(2, 1); pos[6][3] = mp(3, 0);
    pos[7][0] = mp(1, 0); pos[7][1] = mp(1, 1); pos[7][2] = mp(2, 0); pos[7][3] = mp(3, 0);

    Pentamino *penta = new Pentamino('Y', 8, pos);

    return penta;
}

Pentamino* build_Z(){
    std::pair<int,int> **pos = new std::pair<int, int>*[4];
    pos[0] = new std::pair<int, int>[4];
    pos[1] = new std::pair<int, int>[4];
    pos[2] = new std::pair<int, int>[4];
    pos[3] = new std::pair<int, int>[4];
    pos[0][0] = mp(0, 1); pos[0][1] = mp(1, 1); pos[0][2] = mp(2, 1); pos[0][3] = mp(2, 2);
    pos[1][0] = mp(0, 1); pos[1][1] = mp(1, 0); pos[1][2] = mp(2, -1); pos[1][3] = mp(2, 0);
    pos[2][0] = mp(1, 0); pos[2][1] = mp(1, 1); pos[2][2] = mp(1, 2); pos[2][3] = mp(2, 2);
    pos[3][0] = mp(1, -2); pos[3][1] = mp(1, -1); pos[3][2] = mp(1, 0); pos[3][3] = mp(2, -2);

    Pentamino *penta = new Pentamino('Z', 4, pos);

    return penta;
}