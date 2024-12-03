#ifndef PIZZASTORE_H
#define PIZZASTORE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class PizzaStore {
public:
  PizzaStore(); // Default constructor
  PizzaStore(string, int, double, double); // Overloaded constructor
  int tickUpdate(); // Bakes an adds pizzas
  bool consumeSlices(int slices); // Must return false if the order could not be satisfied
  void showStatus(); // Shows how many slices each pizza has. E.g.: Core: 0 4 8
  string getName();
  int getTotalSlicesLeft();  
  void resetPizzas();
private:
  string name;
  int maxPizzas;
  double productionPerTick;
  double successRate;
  vector<int> slicesOfPizzaLeft = {};
  int totalSlicesLeft;
};

#endif 
