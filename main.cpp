#include <iostream>
#include <vector>
#include "model/Network.hpp"
#include "layers/DenseLayer.hpp"
#include "Activation/Relu.hpp"

using namespace Model;
using namespace Layers;
using namespace Activation;

int main() {
    std::cout << "=== TEST FORWARD PROPAGATION (ReLU) ===" << std::endl;

    try {
        Network model;

        auto* layer1 = new DenseLayer<ReLU>(2, 2);

        layer1->weights.data = {0.2, 0.5, -0.4, 0.1};
        layer1->bias.data = {0.1, -0.2};

        model.add(layer1);

        Matrix input(1, 2);
        input.data = {0.5, 0.8};

        // Forward Propagation 
        Matrix prediction = model.predict(input);

        std::cout << "Input X: [0.5, 0.8]" << std::endl;
        std::cout << "Expected Z (before ReLU): [-0.1200,  0.1300]" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Expected Prediction (after ReLU):" << std::endl;
        std::cout << "    0.0000    0.1300" << std::endl;
        std::cout << "Actual Prediction (Your Code):" << std::endl;
        
        prediction.print();

    } catch (const std::exception& e) {
        std::cerr << "CRASHED: " << e.what() << std::endl;
    }

    return 0;
}