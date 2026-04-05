#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP

#include "core/Matrix.hpp"

namespace Activation {
    template<typename Drived>
    class ActivationFunction {
        public:
            Matrix apply_matrix(const Matrix& m) const;
            Matrix derivative_matrix(const Matrix& m) const;

        protected:
            ActivationFunction() = default;
    };
}


#include "Activation.tpp"
#endif