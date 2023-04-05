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

public:
  std::vector<Connection> connections;
  std::vector<Connection> connections_from;

  Neuron() { printf("[Create Neuron]\n"); }

  void AddEdge(Neuron &neuron, double weight) {
    void *neuron_ptr = &neuron;
    this->connections.push_back(Connection({neuron_ptr, weight}));
    neuron.connections_from.push_back(Connection({this, weight}));
  }

  void Predict() {
    for (int i = 0; i < this->connections.size(); ++i) {
      Neuron *nrn = static_cast<Neuron *>(this->connections[i].neuron);
      nrn->AddValue(this->value * this->connections[i].weight);
      // nrn->Predict();
    }
  }

  double Activation(double value) {
    if (value < 0) {
      return 0;
    } else {
      return value;
    }
  }

  void ClearValue() { this->value = 0; }

  double GetValue() const { return this->value; }

  void SetValue(double value) { this->value = value; }

  void AddValue(double value) { this->value += value; }
};

std::ostream &operator<<(std::ostream &os, Neuron &nrn) {
  os << &nrn << " [" << nrn.GetValue() << "]   ";
  for (auto cnc : nrn.connections)
    os << '(' << cnc << "); ";
  os << " | ";
  for (auto cnc : nrn.connections_from)
    os << '(' << cnc << "); ";
  return os;
}
