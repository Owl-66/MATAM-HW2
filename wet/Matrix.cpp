//
// Created by shayhh on 12/18/2025.
//

#include "Matrix.h"

#include <stdexcept>

#include "Utilities.h"

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

    int* temp = new int[rows * columns];
    delete[] this -> matrix;

    this -> rows = other.rows;
    this -> columns = other.columns;
    this -> matrix = temp;

    for (unsigned int i = 0; i < rows * columns; i++) {
        this -> matrix[i] = other.matrix[i];
    }

    return *this;
}



int& Matrix::operator()(unsigned int row, unsigned int column) {
    if (row >= rows || column >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return this->matrix[this->columns*row + column];
}





const int& Matrix::operator()(unsigned int row, unsigned int column) const {
    if (row >= rows || column >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return this->matrix[this->columns*row + column];
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.getRows(); i++) {
        os << "|";
        for (unsigned int j = 0; j < matrix.getColumns(); j++) {
            os << matrix(i,j)<< "|";
        }
        os << std::endl;
    }
    return os;
}

Matrix Matrix::operator-() const{
    Matrix negative = Matrix(this->rows, this->columns);
    for (unsigned int i = 0; i < this->rows; i++) {
        for (unsigned int j = 0; j <this->columns; j++) {
            negative(i, j) = -this->matrix[i*columns + j];
        }
    }
    return negative;
}


Matrix& Matrix::operator*=(int n) {
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < columns; j++) {
            matrix[i*columns + j] *= n;
        }
    }
    return *this;
}


Matrix operator*(int n, const Matrix& matrix) {
    Matrix newMatrix = matrix;
    return newMatrix*=n;
}


Matrix operator*(const Matrix& matrix, int n) {
    return n * matrix;
}


bool operator==(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.columns != matrix2.columns || matrix1.rows != matrix2.rows) {
        return false;
    }
    for (unsigned int i = 0; i < matrix1.rows; i++) {
        for (unsigned int j = 0; j < matrix1.columns; j++) {
            if(matrix1(i, j) != matrix2(i, j)){
                return false;
            }
        }
    }
        return true;
}


bool operator!=(const Matrix& matrix1, const Matrix& matrix2) {
    return !(matrix1 == matrix2);
}


double Matrix::frobenius()const {
    double sumSquares = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sumSquares += matrix[i*columns +j] * matrix[i*columns +j];
        }
    }
    return std:: sqrt(sumSquares);
}


