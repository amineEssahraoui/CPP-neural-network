#ifndef MSE_HPP
#define MSE_HPP

#include <cmath>
#include "Loss.hpp"

namespace Loss {
    class MSE : public LossFunction {
    public:

        double calculate(const Matrix& predicted, const Matrix& target) const override {
            double error = 0.0;
            size_t size_data = predicted.data.size();

            for (size_t i = 0; i < size_data; i++) {
                double diff = predicted.data[i] - target.data[i];
                error += diff * diff; 
            }

            return error / static_cast<double>(size_data);
        }

        Matrix derivative(const Matrix& predicted, const Matrix& target) const override {
            Matrix grad(predicted.rows, predicted.cols); 
            double n = static_cast<double>(grad.data.size());

            for (size_t i = 0; i < grad.data.size(); i++) {
                grad.data[i] = (2.0 / n) * (predicted.data[i] - target.data[i]);
            }
            return grad;
        }
    };
}

#endif