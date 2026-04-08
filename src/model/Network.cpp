#include "model/Network.hpp"
#include <iostream>

namespace Model {

    // Constructor
    Network::Network() : lossFunction(nullptr) {}

    // Destructor
    Network::~Network() {
        for (auto layer : layers) {
            delete layer; 
        }        
        if (lossFunction != nullptr) {
            delete lossFunction;
        }
    }

    void Network::add(Layers::Layer* layer) {
        this->layers.push_back(layer);
    }

    // Loss function 
    void Network::compile(Loss::LossFunction* loss) {
        this->lossFunction = loss;
    }

    // Forward Propagation (Prediction)
    Matrix Network::predict(const Matrix& input) {
        Matrix output = input;
        for (auto layer : layers) {
            output = layer->forward(output);
        }
        return output;
    }

    void Network::train(const Matrix& input, const Matrix& target) {
        if (!lossFunction) {
            std::cerr << "Error: Model not compiled! Call compile() first." << std::endl;
            return;
        }

        Matrix prediction = this->predict(input); 

        std::cout << "Loss = " << this->lossFunction->calculate(prediction, target) << std::endl; 
    }
}