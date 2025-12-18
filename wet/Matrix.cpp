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

    for (unsigned int i = 0; i < rows * columns; i++) {
        this -> matrix[i] = value;
    }
}

Matrix::~Matrix() {
    delete[] this->matrix;
}


unsigned int Matrix::getRows() const {
    return this -> rows;
}

unsigned int Matrix::getColumns() const {
    return this -> columns;
}

int* Matrix::getMatrix() const {
    return this -> matrix;
}


Matrix::Matrix(const Matrix &other) {
    this -> rows = other.rows;
    this -> columns = other.columns;
    this -> matrix = new int[rows * columns];

    for (unsigned int i = 0; i < rows * columns; i++) {
        this -> matrix[i] = other.matrix[i];
    }
}

Matrix& Matrix::operator=(const Matrix &other) {
    if (this == &other) {
        return *this;
    }

    delete[] this -> matrix;

    this -> rows = other.rows;
    this -> columns = other.columns;
    this -> matrix = new int[rows * columns];

    for (unsigned int i = 0; i < rows * columns; i++) {
        this -> matrix[i] = other.matrix[i];
    }

    return *this;
}
