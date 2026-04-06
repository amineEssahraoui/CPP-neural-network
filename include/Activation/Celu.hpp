#ifndef CELU_HPP
#define CELU_HPP

#include "Activation.hpp"
#include <cmath>

namespace Activation {
    class Celu : public ActivationFunction<Celu> {
    public:
        double alpha;

        Celu(double a = 1.0) : alpha(a) {}

        double apply(double x) const {
            return (x >= 0) ? x : alpha * (std::exp(x / alpha) - 1.0);
        }

        double derivative(double x) const {
            return (x >= 0) ? 1.0 : std::exp(x / alpha);
        }
    };
}

#endif