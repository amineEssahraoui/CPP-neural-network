#include "DenseLayer.hpp"

namespace Layers {
    template <typename ActivationType>
    DenseLayer<ActivationType>::DenseLayer(int input_size, int output_size) 
        : weights(input_size, output_size), bias(1, output_size) {
        
        weights.randomize(); 
        bias.randomize(); 
    }

    template <typename ActivationType>
    Matrix DenseLayer<ActivationType>::forward(const Matrix& input){
        // Z = X.W + b
        Matrix Z(input.rows, input.cols) ; 
        Z = input.dot(this->weights);
        Z.add(this->bias);
        // A = f(Z)
        return this->activation.apply_matrix(Z);
    }
}