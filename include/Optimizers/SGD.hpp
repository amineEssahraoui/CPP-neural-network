#ifndef SGD_HPP
#define SGD_HPP

#include "Optimizer.hpp"
#include "core/Matrix.hpp"

namespace Optimizers {
    class SGD : public Optimizer {
    public: 
        SGD(double lr = 0.01); 
        void update(Matrix& weights, Matrix& bias, const Matrix& dW, const Matrix& db) override;
    }; 
}

#endif