//
// Created by shayhh on 12/18/2025.
//

#ifndef WET_MATRIX_H
#define WET_MATRIX_H


class Matrix {
private:
    unsigned int rows;
    unsigned int columns;
    int* matrix;
public:
    Matrix();
    Matrix(unsigned int rows, unsigned int columns, int value = 0);
};


#endif //WET_MATRIX_H