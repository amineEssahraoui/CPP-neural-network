#ifndef LOSS_HPP
#define LOSS_HPP

#include "core/Matrix.hpp"

namespace Loss {
    class LossFunction {
        public: 
            virtual ~LossFunction() = default;
            virtual double calculate(const Matrix& predicted, const Matrix& target) const = 0;
            virtual Matrix derivated(const Matrix& predicted, const Matrix& target) const = 0; 
 
    };
}

#endif