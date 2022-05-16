#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "PilhaLL.h"
#include "Pentamino.h"
#include "Auxiliar.h"

#define mp std::make_pair

int main(int argc, char *args[]){
    
    // user input + matrix construction
    #pragma region
    int rows, columns;
    std::cout << "Número de linhas da Matriz desejada: ";
    std::cin >> rows;
    std::cout << "\nNúmero de colunas da Matriz desejada: ";
    std::cin >> columns;

    if(rows * columns % 5 != 0){
        std:: cout << "\nNão há solução :(\n";
        return 0;
    }

    int **matrix = new int*[rows];

    std::cout << "\nDigite sua Matriz abaixo: \n";
    for(int i = 0 ; i < rows ; i++){
        matrix[i] = new int[columns];
        for(int j = 0 ; j < columns ; j++)
            std::cin >> matrix[i][j];
    }
    #pragma endregion

    // creating every pentamino
    #pragma region
    Pentamino *pentaF = build_F();
    Pentamino *pentaI = build_I();
    Pentamino *pentaL = build_L();
    Pentamino *pentaN = build_N();
    Pentamino *pentaP = build_P();
    Pentamino *pentaT = build_T();
    Pentamino *pentaU = build_U();
    Pentamino *pentaV = build_V();
    Pentamino *pentaW = build_W();
    Pentamino *pentaX = build_X();
    Pentamino *pentaY = build_Y();
    Pentamino *pentaZ = build_Z();
    #pragma endregion

    // creating vector of pentaminos
    #pragma region
    PilhaLL<Pentamino> used;
    PilhaLL<Position> posUsed;
    PilhaLL<int> ind;
    std::vector< std::pair<Pentamino*, bool> > pentaminos;
    pentaminos.push_back(mp(pentaF, false));
    pentaminos.push_back(mp(pentaI, false));
    pentaminos.push_back(mp(pentaL, false));
    pentaminos.push_back(mp(pentaN, false));
    pentaminos.push_back(mp(pentaP, false));
    pentaminos.push_back(mp(pentaT, false));
    pentaminos.push_back(mp(pentaU, false));
    pentaminos.push_back(mp(pentaV, false));
    pentaminos.push_back(mp(pentaW, false));
    pentaminos.push_back(mp(pentaX, false));
    pentaminos.push_back(mp(pentaY, false));
    pentaminos.push_back(mp(pentaZ, false));
    #pragma endregion

    // backtracking com uma pilha
    #pragma region
    int i, j; i = j = 0;
    while(i < rows){
        j = 0;
        bool backtracking = false;
        while(j < columns){
            int k = 0;
            // se a posicao da matriz está livre tento encaixar uma peca
            if(matrix[i][j] == 0){
                // se venho de um backtracking, pego o indice da ultima peca inserida
                if(backtracking){
                    if(!ind.isEmpty()){
                        k = ind.top(); ind.pop();
                    }
                    if(pentaminos[k].first->currVariation == pentaminos[k].first->numVariations){
                        pentaminos[k].first->currVariation = 0;
                        k++;
                    }
                }
                bool filled = false;
                for( ; k < pentaminos.size() ; k++){
                    if(!pentaminos[k].second){
                        if(insert_pentamino(matrix, i, j, rows, columns, pentaminos[k].first->currVariation, pentaminos[k].first)){
                            backtracking = false;
                            Pentamino *pentamino = pentaminos[k].first; used.push(*pentamino);
                            pentamino->currVariation++;
                            Position position = Position(i, j); posUsed.push(position);
                            ind.push(k);
                            pentaminos[k].second = true;
                            filled = true;
                            j++;
                            print_matrix(matrix, rows, columns);
                            std::cout << std::endl;
                            break;
                        }
                    }
                }
                // se não achou nenhuma peca volta um estado no backtracking
                if(!filled){
                    if(!used.isEmpty()){
                        backtracking = true;
                        Pentamino pentamino = used.top(); used.pop();
                        Position backTo = posUsed.top(); posUsed.pop();
                        for(int z = 0 ; z < pentaminos.size() ; z++)
                            if(pentaminos[z].first->letter == pentamino.letter) pentaminos[z].second = false;
                        int iAux = backTo.x;
                        int jAux = backTo.y;
                        i = iAux;
                        j = jAux;
                        remove_pentamino(matrix, iAux, jAux, rows, columns, pentamino.currVariation, pentamino.letter);
                    }
                }
            }
            else j++;
        }
        i++;
    }
    #pragma endregion

    std::cout << "Matriz Resultante: \n";
    print_matrix(matrix, rows, columns);
}