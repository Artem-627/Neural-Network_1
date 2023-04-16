#include <cmath>
#include <iostream>
#include <vector>

#pragma once

struct Connection {
  void *neuron;
  double weight;
};

std::ostream &operator<<(std::ostream &os, Connection cnc) {
  os << cnc.neuron << "; " << cnc.weight;
  return os;
}

class Neuron {
private:
  double value = 0;
  double activation_value = 0;
  double bias = 0;

public:
  // std::vector<Connection> connections;
  std::vector<Connection> connections_from;

  Neuron() {
    std::cout << "[Create Neuron with adress " << this << ']' << '\n';
  }

  void AddInput(Neuron &neuron, double weight) {
    void *neuron_ptr = &neuron;
    // this->connections.push_back(Connection({neuron_ptr, weight}));
    this->connections_from.push_back(Connection({neuron_ptr, weight}));
  }

  // void Predict() {
  //   for (int i = 0; i < this->connections.size(); ++i) {
  //     Neuron *nrn = static_cast<Neuron *>(this->connections[i].neuron);
  //     nrn->AddValue(this->value * this->connections[i].weight);
  //     // nrn->Predict();
  //   }
  // }

  void Predict() {
    for (int i = 0; i < this->connections_from.size(); ++i) {
      Neuron *nrn = static_cast<Neuron *>(this->connections_from[i].neuron);
      this->AddValue(nrn->value * this->connections_from[i].weight);
      // nrn->Predict();
    }
    this->AddValue(this->bias);
  }

  void BackProp(double error, double learning_rate) {
    this->bias -= learning_rate * error * D_Activation(this->activation_value);
    for (int i = 0; i < this->connections_from.size(); ++i) {
      Neuron *nrn = static_cast<Neuron *>(this->connections_from[i].neuron);
      // nrn->AddValue(this->value * this->connections[i].weight);
      this->connections_from[i].weight -= learning_rate * error *
                                          D_Activation(this->activation_value) *
                                          nrn->GetValue();
      // nrn->Predict();
    }
  }

  double Activation(double value) {
    // if (value < 0) {
    //   return 0;
    // } else {
    // return value;
    // }
    return (1 / (1 + exp(-value)));
  }

  double D_Activation(double value) {
    // if (value < 0) {
    //   return 0;
    // } else {
    // return 1;
    // }
    return this->Activation(value) * (1 + this->Activation(value));
  }

  void ClearValue() {
    this->value = 0;
    this->activation_value = 0;
  }

  double GetValue() const { return this->activation_value; }

  double GetBias() const { return this->bias; }

  void SetValue(double value) {
    this->value = value;
    activation_value = this->Activation(this->value);
  }

  void AddValue(double value) {
    this->value += value;
    activation_value = this->Activation(this->value);
  }
};

std::ostream &operator<<(std::ostream &os, Neuron &nrn) {
  os << &nrn << " [" << nrn.GetValue() << "]   ";
  os << nrn.GetBias() << "  |  ";
  for (auto cnc : nrn.connections_from)
    os << '(' << cnc << "); ";
  return os;
}
