#ifndef MAE_HPP
#define MAE_HPP

#include "Loss.hpp"

namespace Loss {
    class MAE : public LossFunction {
    public:

        double calculate(const Matrix& predicted, const Matrix& target) const override {
            double error = 0.0;
            size_t size_data = predicted.data.size();

            for (size_t i = 0; i < size_data; i++) {
                error += std::abs(predicted.data[i] - target.data[i]);
            }

            return error / static_cast<double>(size_data);
        }

        Matrix derivative(const Matrix& predicted, const Matrix& target) const override {
            Matrix grad(predicted.rows, predicted.cols); 
            double n = static_cast<double>(grad.data.size());

            for (size_t i = 0; i < grad.data.size(); i++) {
                double diff = predicted.data[i] - target.data[i];
                if (diff > 0) {
                    grad.data[i] = 1.0/n;  
                } else if (diff < 0) {
                    grad.data[i] = -1.0/n;  
                } else {
                    grad.data[i] = 0; 
                }
            }
            return grad;
        }
    };
}

#endif