#include <iostream>
#include <vector>
#include "model/Network.hpp"
#include "layers/DenseLayer.hpp"
#include "Activation/Sigmoid.hpp"
#include "Loss/MSE.hpp"

using namespace Model;
using namespace Layers;
using namespace Activation;
using namespace Loss;

int main() {
    std::cout << "=== COMPLEX FORWARD TEST (Sigmoid + Multi-Output) ===" << std::endl;

    try {
        Network model;

        // 1. Create a Layer: 3 inputs -> 2 neurons
        auto* layer1 = new DenseLayer<Sigmoid>(3, 2);

        // 2. Set specific weights for testing
        // Weights matrix (3x2): [0.2, 0.5, -0.4, 0.1, 0.3, -0.6]
        layer1->weights.data = {0.2, 0.5, -0.4, 0.1, 0.3, -0.6};
        // Bias matrix (1x2): [0.1, -0.2]
        layer1->bias.data = {0.1, -0.2};

        model.add(layer1);
        model.compile(new MSE());

        // 3. Define Input (1x3) and Target (1x2)
        Matrix input(1, 3);
        input.data = {0.5, -0.2, 0.1};

        Matrix target(1, 2);
        target.data = {0.0, 1.0};

        // 4. Run Prediction
        // Expected Z = [0.31, -0.03]
        // Expected A = [0.5769, 0.4925]
        Matrix prediction = model.predict(input);

        std::cout << "Prediction (Expected ~0.5769, 0.4925):" << std::endl;
        prediction.print();

        // 5. Run Training (Loss Calculation)
        // Expected Loss = 0.2952
        model.train(input, target);

    } catch (const std::exception& e) {
        std::cerr << "CRASHED: " << e.what() << std::endl;
    }

    return 0;
}