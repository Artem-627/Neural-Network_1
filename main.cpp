#include "Source/Neuron.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<Neuron> input(3);
  std::vector<Neuron> hidden(2);
  std::vector<Neuron> output(2);

  input[0].SetValue(0.2);
  input[1].SetValue(0.8);
  input[2].SetValue(2);

  input[0].AddEdge(hidden[0], 0.5);
  input[1].AddEdge(hidden[0], 0.1);
  input[1].AddEdge(hidden[1], 1);
  input[2].AddEdge(hidden[1], 0.75);

  hidden[0].AddEdge(output[0], 0.8);
  hidden[1].AddEdge(output[0], 0.4);
  hidden[1].AddEdge(output[1], 0.3);

  input[0].Predict();
  input[1].Predict();
  input[2].Predict();

  hidden[0].Predict();
  hidden[1].Predict();

  printf("\n---------------\n");
  for (int i = 0; i < input.size(); ++i) {
    std::cout << i << ": " << input[i] << '\n';
  }

  printf("\n---------------\n");
  for (int i = 0; i < hidden.size(); ++i) {
    std::cout << i << ": " << hidden[i] << '\n';
  }

  printf("\n---------------\n");
  for (int i = 0; i < output.size(); ++i) {
    std::cout << i << ": " << output[i] << '\n';
  }

  printf("\n---------------\n");

  return 0;
}
