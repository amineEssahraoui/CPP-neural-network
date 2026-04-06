#ifndef ELU_HPP
#define ELU_HPP

#include "Activation.hpp"
#include <cmath>

namespace Activation {
    class Elu : public ActivationFunction<Elu> {
        public : 
            double alpha; 

            Elu(double a=1.0) : alpha(a){} 

            double apply(double x) const {
                return (x>=0) ? x : alpha * (std::exp(x) - 1);  
            }
            double derivative(double x) const {
                return (x>=0) ? 1.0 : alpha * std::exp(x); 
            }
    };
}

#endif