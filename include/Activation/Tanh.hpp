#ifndef TANH_HPP
#define TANH_HPP

#include "Activation.hpp"
#include <cmath>

namespace Activation {
    class Tanh : public ActivationFunction<Tanh> {
        public : 
            double apply(double x) const {
                return std::tanh(x); 
            }
            double derivative(double x) const {
                double s = apply(x); 
                return 1 - s*s ; 
            }
    };
}

#endif