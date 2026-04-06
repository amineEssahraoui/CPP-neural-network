# C++ Neural Network from Scratch

A lightweight Neural Network library implemented in C++ from the ground up, focusing on core deep learning principles without external linear algebra dependencies.

## Current Progress

The project currently implements the fundamental infrastructure required for a feedforward neural network:

* **Matrix Engine**: A custom `Matrix` class that manages 2D data storage, dot products, matrix addition, and randomization.
* **Activation Framework**: A template-based system using the Curiously Recurring Template Pattern (CRTP) to apply functions and their derivatives to matrices efficiently.
* **Layer Architecture**: Initial implementation of the `DenseLayer` class for fully connected layers, including weight and bias management.

## Mathematical Formulations

The following activation functions and their respective derivatives are implemented:

### 1. ReLU (Rectified Linear Unit)
* **Function**: $f(x) = \max(0, x)$
* **Derivative**: $f'(x) = \begin{cases} 1 & \text{if } x \geq 0 \\ 0 & \text{if } x < 0 \end{cases}$

### 2. Sigmoid
* **Function**: $f(x) = \frac{1}{1 + e^{-x}}$
* **Derivative**: $f'(x) = f(x) \cdot (1 - f(x))$

### 3. Tanh (Hyperbolic Tangent)
* **Function**: $f(x) = \tanh(x)$
* **Derivative**: $f'(x) = 1 - f(x)^2$

### 4. CELU (Continuously Differentiable Exponential Linear Unit)
* **Function**: $f(x) = \max(0, x) + \min(0, \alpha \cdot (e^{x/\alpha} - 1))$
* **Derivative**: $f'(x) = \begin{cases} 1 & \text{if } x \geq 0 \\ e^{x/\alpha} & \text{if } x < 0 \end{cases}$

### 5. ELU (Exponential Linear Unit)
* **Function**: $f(x) = \begin{cases} x & \text{if } x \geq 0 \\ \alpha \cdot (e^x - 1) & \text{if } x < 0 \end{cases}$
* **Derivative**: $f'(x) = \begin{cases} 1 & \text{if } x \geq 0 \\ \alpha \cdot e^x & \text{if } x < 0 \end{cases}$

## Project Structure

* `include/core/`: Matrix logic and linear algebra operations.
* `include/Activation/`: Activation function definitions and implementations.
* `include/layers/`: Neural network layer abstractions.
* `src/`: Source files for core functionality.

## Coming Soon
* Softmax activation, logsigmoid..., and advanced loss functions (MSE, Cross-Entropy...).
* Backpropagation logic and Optimizer implementations (SGD, Adam...).
* Comprehensive model training and evaluation examples.

## Compilation and Execution

To compile the current project with matrix operations and activation tests:

```bash
g++ -I include main.cpp src/core/Matrix.cpp -o main
./main