#pragma once

bool verify(int **matrix, int sizeRow, int sizeColumn, int newRow, int newColumn){
    if(newRow < 0 || newRow >= sizeRow || newColumn < 0 || newColumn >= sizeColumn)
        return false;
    if(matrix[newRow][newColumn] != 0)
        return false;
    return true;
}

bool insert_pentamino(int **matrix, int row, int column, int sizeRow, int sizeColumn, int index, Pentamino* pentamino){
    int rows[4];
    int columns[4];
    
    for(int i = 0 ; i < 4 ; i++){
        int newRow = row + pentamino->pos[index][i].first;
        int newColumn = column + pentamino->pos[index][i].second;
        if(!verify(matrix, sizeRow, sizeColumn, newRow, newColumn)) return false;
        rows[i] = newRow;
        columns[i] = newColumn;
    }

    matrix[row][column] = pentamino->letter;

    for(int i = 0 ; i < 4 ; i++)
        matrix[rows[i]][columns[i]] = pentamino->letter;

    return true;
}

void remove_pentamino(int **matrix, int row, int column, int index, char letter){
    matrix[row][column] = 0;
    
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

    for(int i = 0 ; i < 4 ; i++){
        int newRow = row + pentamino->pos[index][i].first;
        int newColumn = column + pentamino->pos[index][i].second;
        matrix[newRow][newColumn] = 0;
    }
}
