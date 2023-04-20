#include <cmath>
#include <iostream>
#include <vector>

#include "Source/Neuron.h"

/* class Neuron */

// Вывод информации о нейроне
std::ostream &operator<<(std::ostream &os, const Neuron &nrn) {
  os << &nrn << " [" << nrn.GetValue() << "]   ";
  os << nrn.GetBias() << "  |  ";
  for (auto cnc : nrn.connections_from)
    os << '(' << cnc << "); ";
  return os;
}

// Вывод информации о связи
std::ostream &operator<<(std::ostream &os, const Neuron::Connection &cnc) {
  os << cnc.neuron << "; " << cnc.weight;
  return os;
}

// Вывод адрема нейрона при его создании
Neuron::Neuron() {
  std::cout << "[Create Neuron with adress " << this << ']' << '\n';
}

// Добавление входной связи нейрону
void Neuron::AddInput(Neuron &neuron, const double &weight) {
  void *neuron_ptr = &neuron;
  this->connections_from.push_back(Connection({neuron_ptr, weight}));
}

// Предсказания нейрона
void Neuron::Predict() {
  // Очистка прошлого значение нейрона
  this->ClearValue();
  // Сумма произведених входов и соответствующих векторов
  for (int i = 0; i < this->connections_from.size(); ++i) {
    Neuron *nrn = static_cast<Neuron *>(this->connections_from[i].neuron);
    this->AddValue(nrn->value * this->connections_from[i].weight);
  }
  // Учет bias
  this->AddValue(this->bias);
}

// Обучение нейрона
/*
 * Изменение bias
 * Изменение каждого веса
 */
void Neuron::BackProp(const double &error, const double &learning_rate) {
  // Изменение bias
  this->bias -=
      learning_rate * error *
      D_Activation(this->activation_value); // Корректирование значения bias
  // Изменение весов
  for (int i = 0; i < this->connections_from.size(); ++i) {
    Neuron *nrn = static_cast<Neuron *>(this->connections_from[i].neuron);
    this->connections_from[i].weight -= learning_rate * error *
                                        D_Activation(this->activation_value) *
                                        nrn->GetValue(); // Корректирование веса
  }
}

// Фунуция активации
double Neuron::Activation(const double &value) {
  return ((exp(value) - exp(-value)) / (exp(value) + exp(-value)));
}

// Производная функции активации
double Neuron::D_Activation(const double &value) {
  return 1 - pow(this->Activation(value), 2);
}

// Очистка значения нейрона
void Neuron::ClearValue() {
  this->value = 0;
  this->activation_value = 0;
}

// Геттер значения
double Neuron::GetValue() const { return this->activation_value; }

// Геттер bias
double Neuron::GetBias() const { return this->bias; }

// Сеттер значения
void Neuron::SetValue(const double &value) {
  this->value = value;
  activation_value = this->Activation(this->value);
}

// Обновление значения нейрона
void Neuron::AddValue(const double &value) {
  this->value += value;
  activation_value = this->Activation(this->value);
}
