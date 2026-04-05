#include "core/Matrix.hpp"
#include <iostream>
#include <ctime> 
#include <random>

Matrix::Matrix(int r , int c){
    this->rows = r; 
    this->cols = c; 
    this->data.resize(r*c , 0.0);
}

