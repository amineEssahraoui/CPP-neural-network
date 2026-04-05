#include "Activation.hpp"

namespace Activation {
    template <typename Derived>
    Matrix ActivationFunction<Derived>::apply_matrix(const Matrix& m) const {
        int rows_result = m.rows; 
        int cols_result = m.cols; 
        Matrix Result(rows_result,cols_result); 
        for (int i=0; i<m.data.size(); i++) {
            Result.data[i] = tatic_cast<const Derived*>(this)->apply(m.data[i]);
        }
        return Result; 
    }
}