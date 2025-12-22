//
// Created by shayhh on 12/18/2025.
//

#ifndef WET_MATRIX_H
#define WET_MATRIX_H
#include <iosfwd>
#include <ostream>
#include <cmath>



class Matrix {

private:
    unsigned int rows;
    unsigned int columns;
    int* matrix;

public:
    Matrix();
    Matrix(unsigned int rows, unsigned int columns, int value = 0);

    ~Matrix();

    unsigned int getRows() const;
    unsigned int getColumns() const;
    int* getMatrix() const;

    Matrix(const Matrix& other);

    Matrix& operator=(const Matrix& other);

    int& operator()(unsigned int row, unsigned int column);
    const int& operator()(unsigned int row, unsigned int column) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix operator-()const;
    Matrix& operator*=(int n);

    Matrix rotateClockwise() const;
    Matrix rotateCounterClockwise() const;

    friend bool operator==(const Matrix& matrix1, const Matrix& matrix2);

    double frobenius() const;
};

std::ostream& operator<<(std::ofstream& os, const Matrix& matrix);

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);
Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);
Matrix operator*(const Matrix& matrix1, const Matrix& matrix2);
Matrix operator*(int n, const Matrix& matrix);
Matrix operator*(const Matrix& matrix, int n);

bool operator!=(const Matrix& matrix1, const Matrix& matrix2);

#endif //WET_MATRIX_H
