//
// Created by שלומי צרטקוב on 23/12/2025.

#include "MataMvidia.h"

MataMvidia:: MataMvidia() {
    this->numFrames = 0;
    this->frameArray = nullptr;
    this->movieName = "";
    this->creatorName = "";

}


MataMvidia::MataMvidia(const std::string& movieName, const std::string& creatorName,
        const Matrix* frameArray, unsigned int numFrames) {
    this->numFrames = numFrames;
    this->movieName = movieName;
    this->creatorName = creatorName;
    if (numFrames > 0 && frameArray) {
        this->frameArray = new Matrix[numFrames];
        for (unsigned int i = 0; i < numFrames; i++) {
            this->frameArray[i] = frameArray[i];
        }
    }
    else {
        this->frameArray = nullptr;
        this->numFrames = 0;
    }
}

MataMvidia::~MataMvidia() {
    delete[] this->frameArray;
}


MataMvidia::MataMvidia(const MataMvidia& other) {
    this->numFrames = other.numFrames;
    this->movieName = other.movieName;
    this->creatorName= other.creatorName;

    if (other.numFrames > 0 && other.frameArray) {
        this->frameArray = new Matrix[other.numFrames];

        for (unsigned int i = 0; i < other.numFrames; i++) {
            this->frameArray[i] = other.frameArray[i];
        }
    }
        else {
            this->frameArray = nullptr;
            this->numFrames = 0;
    }
}

MataMvidia& MataMvidia::operator=(const MataMvidia& other) {
    if (this == &other) {
        return *this;
    }
    if (other.numFrames > 0 && other.frameArray) {
        Matrix* temp = new Matrix[other.numFrames];

        for (unsigned int i = 0; i < other.numFrames; i++) {
            temp[i] = other.frameArray[i];
        }

        delete[] this->frameArray;
        this->frameArray = temp;
    }
    else {
        delete[] this->frameArray;
        this->frameArray = nullptr;
    }
    this->numFrames = other.numFrames;
    this->movieName = other.movieName;
    this->creatorName = other.creatorName;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const MataMvidia& movie) {
    os << "Movie Name: " << movie.movieName << std::endl;
    os << "Author: " << movie.creatorName << std::endl << std::endl;
    for (unsigned int i = 0; i < movie.numFrames; i++) {
        os << "Frame "<< i << ":"<< std::endl << movie.frameArray[i]<< std::endl << std::endl;
    }
    os << "-----End of Movie-----" ;
    return os;
}



Matrix &MataMvidia::operator[](int index) {
    return frameArray[index];
}

const Matrix &MataMvidia::operator[](int index) const {
    return frameArray[index];
}



MataMvidia &MataMvidia::operator+=(const MataMvidia &other) {
    unsigned int newSize = this -> numFrames + other.numFrames;
    Matrix* newFrameArray = new Matrix[newSize];

    for (unsigned int i = 0; i < this -> numFrames; i++) {
        newFrameArray[i] = this->frameArray[i];
    }
    for (unsigned int i = this -> numFrames; i < newSize; i++) {
        newFrameArray[i] = other.frameArray[i - this -> numFrames];
    }


    delete[] this->frameArray;

    this -> numFrames = newSize;
    this -> frameArray = newFrameArray;

    return *this;
}

MataMvidia &MataMvidia::operator+=(const Matrix &other) {
    std::string fakeName = "not a name";
    MataMvidia temp(fakeName, fakeName, &other, 1);
    *this += temp;
    return *this;
}

MataMvidia operator+(const MataMvidia& movie1, const MataMvidia& movie2) {
    MataMvidia result(movie1);
    result += movie2;
    return result;
}