#include "DenseLayer.hpp"

namespace Layers {
    template <typename ActivationType>
    DenseLayer<ActivationType>::DenseLayer(int input_size, int output_size) : weights(input_size, output_size), bias(1, output_size) {
        weghits.randomize(); 
        bias.randomize(); 
    }

    
}