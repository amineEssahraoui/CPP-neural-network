#ifndef OPTIMIZER_HPP
#define OPTIMIZER_HPP

#include "core/Matrix.hpp"

namespace Optimizers {
    class Optimizer {
        protected:
            double learning_rate; // For all optimizers 

        public:
            // Constructor
            Optimizer(double lr) : learning_rate(lr) {}
            
            // Virtual Destructor 
            virtual ~Optimizer() = default;
            virtual void update(Matrix& weights, Matrix& bias, const Matrix& dW, const Matrix& db) = 0;
    };
}

#endif