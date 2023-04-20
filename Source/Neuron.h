#include <iostream>
#include <vector>

#pragma once

// Класс нейрона
class Neuron {
private:
  double value = 0; // Значение без функции активации
  double activation_value = 0; // Значение после применения функции активации
  double bias = 0;             // Смещение нейрона

  // Активационные функции
  double Activation(const double &value);
  double D_Activation(const double &value);

  Neuron &operator=(Neuron const &);
  Neuron(Neuron const &);

public:
  // Структура связи между двумя нейронами (связывает нейрон с предыдущим
  // нейроном)
  struct Connection {
    void *neuron;  // Адрес входного нейрона
    double weight; // Вес связи

    friend std::ostream &operator<<(std::ostream &os, const Connection &cnc);
  };

  std::vector<Connection> connections_from; // Вектор входных связей нейрона
  Neuron();

  // Основные действия с нейроном
  void AddInput(Neuron &neuron, const double &weight);
  void Predict();
  void BackProp(const double &error, const double &learning_rate);

  // Действия со значением нейрона
  void AddValue(const double &value);
  void ClearValue();
  void SetValue(const double &value);

  // Остальные сеттеры и геттеры
  double GetValue() const;
  double GetBias() const;

  friend std::ostream &operator<<(std::ostream &os, const Neuron &nrn);
};
