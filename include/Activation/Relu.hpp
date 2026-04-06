#ifndef RELU_HPP
#define RELU_HPP

#include "Activation.hpp"

namespace Activation {
    class ReLU : public ActivationFunction<ReLU> {
    public:
        double apply(double x) const {
            return (x >= 0) ? x : 0.0; 
        }

        double derivative(double x) const {
            return (x >= 0) ? 1.0 : 0.0;
        }
    };
}

#endif