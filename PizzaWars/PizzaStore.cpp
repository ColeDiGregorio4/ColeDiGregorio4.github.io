//Cole DiGregorio                                                                                                                                                                                                     
//C11110105                                                                                                                                                                                                           
//Pizza Wars project
#include "PizzaStore.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

PizzaStore::PizzaStore(){ //default constuctor 
  name = "";
  maxPizzas = 0;
  productionPerTick = 0.0;
  successRate = 0.0;
  totalSlicesLeft = 0;
}

PizzaStore::PizzaStore(string nameIn, int maxPizzasIn, double productionPerTickIn, double successRateIn) { //overloaded constructor 
  name = nameIn;
  maxPizzas = maxPizzasIn;
  productionPerTick = productionPerTickIn;
  successRate = successRateIn;
  totalSlicesLeft = maxPizzas * 8;
  for (int i = 0; i < maxPizzas; i++){ //seting my vector to have 8 slices for each pizza 
    slicesOfPizzaLeft.push_back(8);
  }
}

int PizzaStore::tickUpdate(){
  int pizzasToBake = rand() % (maxPizzas + 1); //getting a random amount of pizzas a store can make
  int bakedPizzas = static_cast<int>(pizzasToBake * successRate); //geting the pizzas they can make with a chance of them dropping some
  int pizzasLeft = bakedPizzas;
  int pizzasAdded = 0;
  for (int i = 0; i < slicesOfPizzaLeft.size(); i++){ //run through vector
    if (slicesOfPizzaLeft[i] == 0){ //if there is no pizza in that point in the vector move on 
      if (pizzasLeft > 0){ //if there are still pizzas left to add 
	slicesOfPizzaLeft[i] = 8; //add a pizza 
	pizzasLeft--; //since you added a pizza take away a pizza
	totalSlicesLeft += 8; //get the total slices with the new pizza
	pizzasAdded++; //count how many pizzas are added
      }
    }else {
      //cout << "NO PIZZA ADDED" << endl;
    }
  }
  cout << pizzasAdded << " pizza(s) were added at " << getName() << endl;
  return bakedPizzas; //I dont know why we send this back im assuming its for what I printed above but i really dont want to mess up what i have sorry 
}

bool PizzaStore::consumeSlices(int slices){
  if (totalSlicesLeft <= 0) { //if the total slices are negitive there is no more to eat
    return false;  // No slices left to consume
  }
  
  bool allSlicesConsumed = true; //the check below will change this if they eat every slice

  for (int i = 0; i < slices; i++) { //loop through each slice eaten
    bool sliceConsumed = false; //if the slice was eaten 
    
    int j = 0;
    while (j < slicesOfPizzaLeft.size() && !sliceConsumed) {
      if (slicesOfPizzaLeft[j] > 0) {
	slicesOfPizzaLeft[j]--;
	sliceConsumed = true;
      }
      j++;
    }
    
    if (!sliceConsumed) {
      allSlicesConsumed = false; //if all the slices werent eat then they lost
    }
  }
  
  if (allSlicesConsumed) { //if they eat all of them then it should update the total slices
    totalSlicesLeft -= slices;
  }
  
  return allSlicesConsumed; //all of the slices were eaten or not
}

void PizzaStore::showStatus(){
  cout << getName() << ": "; //print name
  for (int i = 0; i < maxPizzas; i++){
    cout << slicesOfPizzaLeft[i] << " "; //loop throught vector and print the number of slices in each pizza 
  }
  
  cout << endl;
}

string PizzaStore::getName(){
  return name;
}

int PizzaStore::getTotalSlicesLeft(){
  return totalSlicesLeft;
}



