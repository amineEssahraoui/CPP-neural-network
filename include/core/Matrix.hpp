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

    // Core operations (new result): 
    Matrix dot(const Matrix& other) const; 
    Matrix add(const Matrix& other) const;         
    Matrix subtract(const Matrix& other) const;     
    Matrix multiply(const Matrix& other) const; 
    Matrix transpose() const; 
    Matrix multiply_by_elemnt(const double element) const;

    // Core operations (inplace : change the original matrix): 
    void add_inplace(const Matrix& other); 
    void subtract_inplace(const Matrix& other); 
    void subtract_scaled(const Matrix& other, double scalar);

    // Getters , helpers : 
    double at(int r , int c) const; // The correct position in flaty array for an element in [r,c]
    void randomize(); 
    void print() const; 
} ; 

#endif