#include "Optimizers/SGD.hpp"

namespace Optimizers {
    SGD::SGD(double lr) : Optimizer(lr) {}

    void SGD::update(Matrix& weights, Matrix& bias, const Matrix& dW, const Matrix& db) {
        weights.subtract_scaled(dW, this->learning_rate); 
        bias.subtract_scaled(db, this->learning_rate);         
    }
}