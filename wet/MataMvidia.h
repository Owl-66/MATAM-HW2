//
// Created by שלומי צרטקוב on 23/12/2025.
//
#pragma once

#include <string>
#include "Matrix.h"
#include <ostream>



class MataMvidia {
private:
    unsigned int numFrames;
    Matrix* frameArray;
    std::string movieName;
    std::string creatorName;
public:
    MataMvidia();
    MataMvidia(const std::string& movieName, const std::string& creatorName,
        const Matrix* frameArray, unsigned int numFrames);

    ~MataMvidia();


    MataMvidia(const MataMvidia& other);
    MataMvidia& operator=(const MataMvidia& other);

    friend std::ostream& operator<<(std::ostream& os, const MataMvidia& movie);
    Matrix& operator[](int index);
    const Matrix& operator[](int index) const;

    MataMvidia& operator+=(const MataMvidia& other);
    MataMvidia& operator+=(const Matrix& other);
};

};

MataMvidia operator+(const MataMvidia& movie1, const MataMvidia& movie2);

