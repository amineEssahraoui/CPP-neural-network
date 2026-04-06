#include <iostream>
#include "core/Matrix.hpp"
#include "Activation/Relu.hpp"
#include "Activation/Sigmoid.hpp"
#include "Activation/Tanh.hpp"

using namespace std;
using namespace Activation;

int main() {
    Matrix m(2, 3);
    m.randomize();
    
    cout << "========== Matrix Originale ==========" << endl;
    m.print();
    cout << endl;

    ReLU relu;
    Matrix m_relu = relu.apply_matrix(m); 
    Matrix d_relu = relu.derivative_matrix(m); 
    
    cout << "========== Test ReLU ==========" << endl;
    cout << "Applied ReLU:" << endl;
    m_relu.print();
    cout << "Derivative ReLU:" << endl;
    d_relu.print();
    cout << endl;

    Sigmoid sigmoid;
    Matrix m_sig = sigmoid.apply_matrix(m);
    Matrix d_sig = sigmoid.derivative_matrix(m);
    
    cout << "========== Test Sigmoid ==========" << endl;
    cout << "Applied Sigmoid:" << endl;
    m_sig.print();
    cout << "Derivative Sigmoid:" << endl;
    d_sig.print();
    cout << endl;

    Tanh tanh_func;
    Matrix m_tanh = tanh_func.apply_matrix(m);
    Matrix d_tanh = tanh_func.derivative_matrix(m);
    
    cout << "========== Test Tanh ==========" << endl;
    cout << "Applied Tanh:" << endl;
    m_tanh.print();
    cout << "Derivative Tanh:" << endl;
    d_tanh.print();
    cout << endl;

    return 0;
}