#include "core/Matrix.hpp"
#include <iostream>
#include <ctime> 
#include <random>

Matrix::Matrix(int r , int c){
    this->rows = r; 
    this->cols = c; 
    this->data.resize(r*c , 0.0);
}

double Matrix::at(int r, int c) const{
    int index = r*this->cols + c; 
    return this->data[index] ; 
}