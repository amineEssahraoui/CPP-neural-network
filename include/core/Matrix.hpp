#ifndef MATRIX_HPP
#define MATRIX_HPP
using namespace std ; 

#include <vector> 
#include <iostream>

class Matrix {
    public : 
    int rows , cols; 
    vector<double> data; // Flaty array

    // Constructors : 
    Matrix(int r , int c); 

    // Core operations : 
    Matrix dot(const Matrix& other); 
    void add(const Matrix& other); 

    // Getters , helpers : 
    double at(int r , int c) const; // The correct position in flaty array for an element in [r,c]
    void randomize(); 
    void print() const; 
} ; 

#endif