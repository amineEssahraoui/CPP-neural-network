#ifndef DENSE_LAYER_HPP
#define DENSE_LAYER_HPP

#include "core/Matrix.hpp"
#include "Activation/Activation.hpp"

namespace Layers {
    template <typename ActivationType> 
    class DenseLayer {
        public : 
            Matrix weghits; 
            Matrix bias; 
            ActivationType activation; 

            DenseLayer(int input_size, int output_size); // Constructor
            Matrix forward(const Matrix& input) const;  // A simple function for froward propagation

    };
}

#include "DenseLayer.tpp"

#endif