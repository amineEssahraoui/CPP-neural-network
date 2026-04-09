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
    Matrix dot(const Matrix& other) const; 
    void add(const Matrix& other); 
    void subtract(const Matrix& other); 
    Matrix multiply(const Matrix& other) const; 
    Matrix transpose() const; 
    Matrix multiply_by_elemnt(const double element) const; 

    // Getters , helpers : 
    double at(int r , int c) const; // The correct position in flaty array for an element in [r,c]
    void randomize(); 
    void print() const; 
} ; 

#endif