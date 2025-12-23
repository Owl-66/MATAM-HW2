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
