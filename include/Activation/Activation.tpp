#include "Activation.hpp"

namespace Activation {
    template <typename Derived>
    Matrix ActivationFunction<Derived>::apply_matrix(const Matrix& m) const {
        Matrix Result(m.rows, m.cols); 
        for (size_t i = 0; i < m.data.size(); i++) {
            Result.data[i] = static_cast<const Derived*>(this)->apply(m.data[i]);
        }
        return Result; 
    }

    template <typename Derived>
    Matrix ActivationFunction<Derived>::derivative_matrix(const Matrix& m) const {
        Matrix Result(m.rows, m.cols); 
        for (size_t i = 0; i < m.data.size(); i++) {
            Result.data[i] = static_cast<const Derived*>(this)->derivative(m.data[i]);
        }
        return Result;
    }
}