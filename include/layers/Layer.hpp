#ifndef LAYER_HPP
#define LAYER_HPP

#include "core/Matrix.hpp"

namespace Layers {
    /**
     * @brief The abstract base class for all neural network layers.
     * This allows us to store different types of layers in a single container.
     */
    class Layer {
        public:
            virtual ~Layer() = default;
            virtual Matrix forward(const Matrix& input) = 0;
    };
}

#endif