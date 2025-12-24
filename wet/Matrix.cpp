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

    int* temp = new int[other.rows * other.columns];
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
    for (unsigned int i = 0; i < matrix.rows; i++) {
        os << "|";
        for (unsigned int j = 0; j < matrix.columns; j++) {
            os << matrix(i,j)<< "|";
        }
        os << std::endl;
    }
    return os;
}




Matrix& Matrix::operator+=(const Matrix& other) {
    if (this -> rows != other.rows || this -> columns != other.columns) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    for (unsigned int i = 0; i < this -> rows; i++) {
        for (unsigned int j = 0; j < this -> columns; j++) {
            this -> matrix[i * this -> columns + j] += other(i, j);
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    return *this += (-other);
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (this -> columns != other.rows) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix temp(this -> rows, other.columns);
    int rowSum = 0;
    for (unsigned int row = 0; row < this -> rows; row++) {
        for (unsigned int column = 0; column < other.columns; column++) {
            rowSum = 0;
            for (unsigned int i = 0; i < this -> columns; i++) {
                rowSum += this->matrix[row * this -> columns + i] * other(i, column);
            }
            temp(row, column) = rowSum;
        }
    }
    *this = temp;
    return *this;
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



Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix result(matrix1);
    result += matrix2;
    return result;
}

Matrix operator-(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix result(matrix1);
    result -= matrix2;
    return result;
}

Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix result(matrix1);
    result *= matrix2;
    return result;
}

Matrix operator*(int n, const Matrix& matrix) {
    Matrix newMatrix = matrix;
    return newMatrix*=n;
}

Matrix operator*(const Matrix& matrix, int n) {
    return n * matrix;
}




Matrix Matrix::rotateClockwise() const {
    Matrix result(this -> columns, this -> rows);

    for (unsigned int row = 0; row < result.rows; row++) {
        for (unsigned int column = 0; column < result.columns; column++) {
            result.matrix[row * result.columns + column] = this -> matrix[(this->rows - column - 1) * (this -> columns) + row];
        }
    }
    return result;
}

Matrix Matrix::rotateCounterClockwise() const {
    Matrix result(this -> columns, this -> rows);

    for (unsigned int row = 0; row < result.rows; row++) {
        for (unsigned int column = 0; column < result.columns; column++) {
            result.matrix[row * result.columns + column] = this -> matrix[column * (this -> columns) + (this->columns - row - 1)];
        }
    }
    return result;
}



Matrix Matrix::transpose() const {
    Matrix result(this -> columns, this -> rows);
    for (unsigned int row = 0; row < result.rows; row++) {
        for (unsigned int column = 0; column < result.columns; column++) {
            result.matrix[row * result.columns + column] = this->matrix[column * (this -> columns) + row];
        }
    }
    return result;
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


double Matrix::CalcFrobeniusNorm(const Matrix& m){
    double sumSquares = 0;
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            sumSquares += m.matrix[i*m.columns +j] * m.matrix[i*m.columns +j];
        }
    }
    return std:: sqrt(sumSquares);
}


int Matrix::CalcDeterminant(const Matrix& m){
    if (m.columns != m.rows) {
        exitWithError(MatamErrorType::NotSquareMatrix);
    }
    if (m.columns == 1) {
        return m.matrix[0];
    }


    int determinant = 0;
    Matrix temp(m.rows -1, m.columns -1);
    for (int i = 0; i < m.columns; i++) {
        for (int row = 1; row < m.rows; row++) {
            for (int column = 0; column < m.columns; column++) {
                if (column < i) {
                    temp(row - 1, column) = m.matrix[row * m.columns + column];
                }else if (column > i) {
                    temp(row - 1, column - 1) = m.matrix[row * m.columns + column];
                }
            }
        }
        if (i % 2 == 0) {
            determinant += m.matrix[i] * CalcDeterminant(temp);
        }else {
            determinant -= m.matrix[i] * CalcDeterminant(temp);
        }
    }
    return determinant;
}


