#include <iostream>
#include <vector>
#include "layers/DenseLayer.hpp"
#include "Activation/Relu.hpp"
#include "Optimizers/SGD.hpp"

using namespace Layers;
using namespace Activation;
using namespace Optimizers;

int main() {
    std::cout << "=== TEST SGD OPTIMIZER (In-place update) ===" << std::endl;

    try {
        auto* layer1 = new DenseLayer<ReLU>(2, 2);

        layer1->weights.data = {0.2, 0.5, -0.4, 0.1}; 
        layer1->bias.data = {0.1, -0.2};              

        SGD optimizer(0.1);

        Matrix dW(2, 2);
        dW.data = {0.1, -0.1, 0.2, 0.0}; 
        
        Matrix db(1, 2);
        db.data = {0.05, -0.05};

        std::cout << "\n[Initial State - Before Training]" << std::endl;
        std::cout << "Weights:" << std::endl; layer1->weights.print();
        std::cout << "Bias:" << std::endl; layer1->bias.print();

        for (int step = 1; step <= 3; step++) {
            std::cout << "\n--- STEP " << step << " ---" << std::endl;
            
            optimizer.update(layer1->weights, layer1->bias, dW, db);
            
            std::cout << "Weights updated:" << std::endl; 
            layer1->weights.print();
            std::cout << "Bias updated:" << std::endl; 
            layer1->bias.print();
        }

    } catch (const std::exception& e) {
        std::cerr << "CRASHED: " << e.what() << std::endl;
    }

    return 0;
}