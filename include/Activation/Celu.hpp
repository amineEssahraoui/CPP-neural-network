#ifndef CELU_HPP
#define CELU_HPP

#include "Activation.hpp"
#include <cmath>
#include <stdexcept> 

namespace Activation {
    class Celu : public ActivationFunction<Celu> {
    private:
        double alpha; 
    public:
        Celu(double a = 1.0) {
            setAlpha(a);
        }

        void setAlpha(double a) {
            if (a == 0) {
                this->alpha = 1e-7; 
            } else {
                this->alpha = a;
            }
        }

        double getAlpha() const { return alpha; }

        double apply(double x) const {
            return (x >= 0) ? x : alpha * (std::exp(x / alpha) - 1.0);
        }

        double derivative(double x) const {
            return (x >= 0) ? 1.0 : std::exp(x / alpha);
        }
    };
}

#endif