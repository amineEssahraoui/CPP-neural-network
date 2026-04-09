#include "core/Matrix.hpp"
#include <iostream>
#include <ctime> 
#include <random>
#include <iomanip>

Matrix::Matrix(int r , int c){
    this->rows = r; 
    this->cols = c; 
    this->data.resize(r*c , 0.0);
}

double Matrix::at(int r, int c) const{
    int index = r*this->cols + c; 
    return this->data[index] ; 
}

Matrix Matrix::dot(const Matrix& other) const{
    // checking dim : 
    if (this->cols != other.rows) {
        cerr << "Error: Dimensions mismatch for dot product!" << endl ; 
        return Matrix(0,0); 
    }
    int row_result = this->rows ; 
    int n = this->cols ; 
    int cols_result = other.cols ; 
    Matrix Result(row_result, cols_result); 

    for (int i=0 ; i<row_result ; i++) {
        for (int j=0 ; j<cols_result ; j++) {
            for (int k=0 ; k<n ; k++) {
                Result.data[i*cols_result + j] += this->at(i,k)*other.at(k,j); 
            }
        }
    }
    return Result ; 
}

void Matrix::add_inplace(const Matrix& other) {
    if (!(this->rows==other.rows && this->cols==other.cols)) {
        cerr << "Error: Invalid dimensions for matrix addition!" << endl;
        return ; 
    }
    
    for (int i = 0; i < this->data.size(); i++) {
        this->data[i] += other.data[i];
    }
}

void Matrix::randomize() {
    static int seed = 42; // Fixed seed in the first time for a simple debug ! 
    static mt19937 gen(seed); 
    uniform_real_distribution<double> distr(-1.0 , 1.0); 
    for (int i=0; i<this->data.size(); i++) {
        double random_number = distr(gen);
        this->data[i] = random_number ; 
    }
}

void Matrix::print() const {

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << this->at(i, j);
        }
        std::cout << std::endl;
    }
}

void Matrix::subtract_inplace(const Matrix& other) {
    // Check dimensions first!
    if (this->rows != other.rows || this->cols != other.cols) {
        std::cerr << "Error: Dimensions mismatch for subtraction!" << std::endl;
        return;
    }
    for(size_t i = 0; i < this->data.size(); i++) {
        this->data[i] -= other.data[i]; 
    }
}

Matrix Matrix::multiply(const Matrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        std::cerr << "Error: Dimensions mismatch for element-wise multiplication!" << std::endl;
        return Matrix(0, 0);
    }
    Matrix result(this->rows, this->cols); 
    for (size_t i = 0; i < result.data.size(); i++) {
        result.data[i] = this->data[i] * other.data[i]; 
    }
    return result; 
}

Matrix Matrix::transpose() const {
    // New dimensions: Rows become Cols, Cols become Rows
    Matrix transpose_matrix(this->cols, this->rows); 

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            // Element at (i, j) in original goes to (j, i) in transposed
            // Index in transposed: j * transposed_cols + i (where transposed_cols is original this->rows)
            transpose_matrix.data[j * this->rows + i] = this->at(i, j); 
        }
    }
    return transpose_matrix; 
}

Matrix Matrix::multiply_by_elemnt(const double element) const{
    Matrix Result(this->rows, this->cols); 
    for(int i=0; i<this->data.size(); i++){
        Result.data[i] = this->data[i] * element ; 
    }
    return Result; 
}