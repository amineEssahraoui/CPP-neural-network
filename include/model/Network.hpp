#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include "layers/Layer.hpp"
#include "Loss/Loss.hpp"
#include "core/Matrix.hpp"

namespace Model {
    class Network {
    private:
        std::vector<Layers::Layer*> layers; 
        Loss::LossFunction* lossFunction;

    public:
        Network();
        ~Network();
        void add(Layers::Layer* layer);
        void compile(Loss::LossFunction* loss);
        Matrix predict(const Matrix& input);
        void train(const Matrix& input, const Matrix& target);
    };
}

#endif