#include <iostream>
#include "model/Network.hpp"
#include "layers/DenseLayer.hpp"
#include "Activation/Relu.hpp"
#include "Loss/MSE.hpp"

using namespace Model;
using namespace Layers;
using namespace Activation;
using namespace Loss;

int main() {
    std::cout << "[CHECKPOINT 1] Start of Program" << std::endl;

    try {
        Network model;
        std::cout << "[CHECKPOINT 2] Model object created" << std::endl;

        auto* layer1 = new DenseLayer<ReLU>(2, 1);
        std::cout << "[CHECKPOINT 3] Layer created" << std::endl;

        layer1->weights.data = {0.5, 0.5};
        layer1->bias.data = {0.1};
        std::cout << "[CHECKPOINT 4] Weights and Bias assigned" << std::endl;

        model.add(layer1);
        model.compile(new MSE());
        std::cout << "[CHECKPOINT 5] Model compiled" << std::endl;

        Matrix input(1, 2);
        input.data = {1.0, 2.0};
        Matrix target(1, 1);
        target.data = {1.0};
        std::cout << "[CHECKPOINT 6] Input/Target ready" << std::endl;

        std::cout << "[CHECKPOINT 7] Starting Predict..." << std::endl;
        Matrix prediction = model.predict(input);
        std::cout << "[CHECKPOINT 8] Predict Finished!" << std::endl;

        std::cout << "Prediction : ";
        prediction.print(); 

        std::cout << "\n[CHECKPOINT 9] Starting Train..." << std::endl;
        model.train(input, target); 
        std::cout << "[CHECKPOINT 10] Train Finished!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "CRASHED with error: " << e.what() << std::endl;
    }

    std::cout << "\n[END] Press Enter to close..." << std::endl;
    std::cin.get(); 
    return 0;
}