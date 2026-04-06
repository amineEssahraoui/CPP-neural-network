#ifndef SIGMOID_HPP
#define SIGMOID_HPP

#include "Activation.hpp"
#include <cmath>

namespace Activation {
    class Sigmoid : public ActivationFunction<Sigmoid> {
        public : 
            double apply(double x) const {
                return 1.0/(1+ std::exp(-x)); 
            }
            double derivative(double x) const {
                double s = apply(x); 
                return s * (1-s); 
            }
    };
}

#endif