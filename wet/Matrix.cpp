//
// Created by shayhh on 12/18/2025.
//

#include "Matrix.h"

Matrix::Matrix() {
    this -> rows = 0;
    this -> columns = 0;
    this -> matrix = nullptr;
}

Matrix::Matrix(unsigned int rows, unsigned int columns, int value) {
    this -> rows = rows;
    this -> columns = columns;
    this -> matrix = new int[rows * columns];
    for (int i = 0; i < rows * columns; i++) {
        this -> matrix[i] = value;
    }
}

