#ifdef SGD_HPP
#define SGD_HPP

#include "Optimizer.hpp"

namespace Optimizers {
    class SGD : public Optimizer {
        SGD(double lr = 0.01); 
        void update(Matrix& weights, Matrix& bias, const Matrix& dW, const Matrix& db) override;
    }; 
}

#endif