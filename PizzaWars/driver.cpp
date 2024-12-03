//Cole DiGregorio
//Project 2
//Pizza Wars
//C11110105

#include <iostream>
#include "MysteryMachine.h"
#include "Date.h"
#include "PizzaStore.h"
#include "PizzaWars.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

int main (){
  
  srand (time(0)); //set a seed for randoms
  PizzaWars pizzawars; //create a Pizza wars object 
  pizzawars.runSimulation(); //run the project

}

