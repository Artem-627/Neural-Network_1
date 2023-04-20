#include "Source/Neuron.h"
#include <cmath>
#include <iostream>
#include <vector>

const double learning_rate = .01;

void Learn(Neuron &nrn, Neuron &in1, Neuron &in2, int x, int y, int out) {
  in1.SetValue(x);
  in2.SetValue(y);

  nrn.Predict();
  std::cout << nrn << '\n';
  // std::cout << nrn.GetValue() << '\n' << '\n';

  nrn.BackProp(nrn.GetValue() - out, learning_rate);
}

int main() {
  std::vector<Neuron> input(2);
  std::vector<Neuron> output(1);

  output[0].AddInput(input[0], 1.45);
  output[0].AddInput(input[1], 4.12);

  for (int i = 0; i < 100; ++i) {
    Learn(output[0], input[0], input[1], 2, 1, 1);
    Learn(output[0], input[0], input[1], 0, 0, -1);
    Learn(output[0], input[0], input[1], 1, 4, 1);
    Learn(output[0], input[0], input[1], 4, -3, -1);
    Learn(output[0], input[0], input[1], 1, 2, 1);
    Learn(output[0], input[0], input[1], -2, 0, -1);
    Learn(output[0], input[0], input[1], -2, 4, 1);
    Learn(output[0], input[0], input[1], -4, 1, -1);
    Learn(output[0], input[0], input[1], -1, 3, 1);
    Learn(output[0], input[0], input[1], -1, 1, -1);
    Learn(output[0], input[0], input[1], 4, 1, 1);
    Learn(output[0], input[0], input[1], 2, -2, -1);
    Learn(output[0], input[0], input[1], 2, 2, 1);
    Learn(output[0], input[0], input[1], -3, 2, -1);
    Learn(output[0], input[0], input[1], 4, -1, 1);
    Learn(output[0], input[0], input[1], 1, -1, -1);
    Learn(output[0], input[0], input[1], -1, 2, 1);
    Learn(output[0], input[0], input[1], -4, 3, -1);
  }

  return 0;
}
