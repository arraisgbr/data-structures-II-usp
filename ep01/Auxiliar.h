#pragma once

#include<iostream>
#include<vector>
#include<algorithm>
#include "Pentamino.h"
#include "PilhaLL.h"

class Position{
    public:
        int x, y;
        Position(){}
        Position(int x, int y){
            this->x = x;
            this->y = y;
        }
};

bool verify(int **matrix, int sizeRow, int sizeColumn, int newRow, int newColumn){
    if(newRow < 0 || newRow >= sizeRow || newColumn < 0 || newColumn >= sizeColumn)
        return false;
    if(matrix[newRow][newColumn] != 0)
        return false;
    return true;
}

bool weakVerify(int **matrix, int sizeRow, int sizeColumn, int newRow, int newColumn){
    if(newRow < 0 || newRow >= sizeRow || newColumn < 0 || newColumn >= sizeColumn)
        return false;
    return true;
}

bool insert_pentamino(int **matrix, int row, int column, int sizeRow, int sizeColumn, int index, Pentamino* pentamino){
    std::vector<int> rows;
    std::vector<int> columns;    
    int variations = pentamino->numVariations;

    for(int i = 0 ; i < 4 ; i++){
        int newRow = row + pentamino->pos[index][i].first;
        int newColumn = column + pentamino->pos[index][i].second;
        if(!verify(matrix, sizeRow, sizeColumn, newRow, newColumn)) return false;
        rows.push_back(newRow);
        columns.push_back(newColumn);
    }
    
    matrix[row][column] = pentamino->letter;

    for(int i = 0 ; i < 4 ; i++)
        matrix[rows[i]][columns[i]] = pentamino->letter;

    return true;
}

void remove_pentamino(int **matrix, int row, int column, int sizeRow, int sizeColumn, int index, char letter){
    Pentamino *pentamino;
    if(letter == 'F')
        pentamino = build_F();
    else if(letter == 'I')
        pentamino = build_I();
    else if(letter == 'L')
        pentamino = build_L();
    else if(letter == 'N')
        pentamino = build_N();
    else if(letter == 'P')
        pentamino = build_P();
    else if(letter == 'T')
        pentamino = build_T();
    else if(letter == 'U')
        pentamino = build_U();
    else if(letter == 'V')
        pentamino = build_V();
    else if(letter == 'W')
        pentamino = build_W();
    else if(letter == 'X')
        pentamino = build_X();
    else if(letter == 'Y')
        pentamino = build_Y();
    else if(letter == 'Z')
        pentamino = build_Z();

    int variations = pentamino->numVariations;
    std::vector<int> rows;
    std::vector<int> columns;
    for(int i = 0 ; i < 4 ; i++){
        int newRow = row + pentamino->pos[index][i].first;
        int newColumn = column + pentamino->pos[index][i].second;
        if(!weakVerify(matrix, sizeRow, sizeColumn, newRow, newColumn)) return;
        else if(matrix[newRow][newColumn] != pentamino->letter) return;
        else{
            rows.push_back(newRow);
            columns.push_back(newColumn);
        }
    }

    matrix[row][column] = 0;
    for(int i = 0 ; i < 4 ; i++)
        matrix[rows[i]][columns[i]] = 0;
    return;
}

void print_matrix(int **matrix, int rows, int columns){
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            if(matrix[i][j] != 0 && matrix[i][j] != 1) std::cout << char(matrix[i][j]) << " ";
            else std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}