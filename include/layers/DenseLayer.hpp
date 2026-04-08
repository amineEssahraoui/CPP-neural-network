#ifndef DENSE_LAYER_HPP
#define DENSE_LAYER_HPP

#include "core/Matrix.hpp"
#include "Activation/Activation.hpp"
#include "Layer.hpp" // 

namespace Layers {
    template <typename ActivationType> 
    class DenseLayer : public Layer {
        public : 
            Matrix weights; 
            Matrix bias; 
            ActivationType activation; 

            DenseLayer(int input_size, int output_size); 
            Matrix forward(const Matrix& input) override; 
    };
}

#include "DenseLayer.tpp"

#endif