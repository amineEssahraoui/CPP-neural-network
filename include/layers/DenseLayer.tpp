#include "DenseLayer.hpp"

namespace Layers {
    template <typename ActivationType>
    DenseLayer<ActivationType>::DenseLayer(int input_size, int output_size) 
        : weights(input_size, output_size), biases(1, output_size) {
        
        weights.randomize(); 
        biases.randomize(); 
    }

    template <typename ActivationType>
    Matrix DenseLayer<ActivationType>::forward(const Matrix& input) const {
        // Z = X.W + b
        Matrix Z = input.dot(this->weights).add(this->biases);         
        // A = f(Z) , where f is the activation function
        return this->activation.apply_matrix(Z);
    }
}