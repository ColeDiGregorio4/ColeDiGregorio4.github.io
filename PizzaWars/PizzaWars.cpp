//Cole DiGregorio
//C11110105
//Pizza Wars project

#include "PizzaWars.h"
#include "PizzaStore.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <limits>
#include <unistd.h>
using namespace std;

PizzaWars::PizzaWars(){ //needed for contrustor
 
}

void PizzaWars::runSimulation(){ //main driver of the programer
  int month;
  int day;
  int year;
  
  cout << "Welcome to Pizza Wars!" << endl;
  cout << "This program simulates an epic battle between Core and Schilletter and their ability to keep up with the demand for pizza!" << endl << endl;
  cout << "Please enter the date you'd like to start the simulation in MM DD YYYY format: ";
  //cin >> month >> day >> year;
  bool validInput = false; //if the user enters somthing wrong

  while (!validInput) { //while the user has messed up 
    cout << "Please enter the date you'd like to start the simulation in MM DD YYYY format: ";
    if (cin >> month >> day >> year) { //if the user inputs a string or char this will be false
      if (month >= 1 && month <= 12 && day >= 1 && day <= 31 && year >= 0) { //check if the date makes sense in date context
	validInput = true; //if it does end loop
      } else {
	cout << "Invalid date. Please enter a valid date." << endl; //if not then its a problem
      }
    } else {
      cin.clear(); //clear the input 
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this why i have included limits and I got this validation check from c plus plus and have been doing in my labs: if i dont add numeric_limits<streamsize>::max(), '\n' then if the user inputs "abc" the error message will print out 3 times (however many letters they enter)
      cout << "Invalid input. Please enter a valid date in the format MM DD YYYY." << endl;
    }
  }

  Date startingDate; //seting a date object 
  startingDate.setMonth(month);
  startingDate.setDay(day);
  startingDate.setYear(year);

    
  Date* dates = allocateWeekOfDates(startingDate); //set a date object pointer that acts like a array of dates that it can point a sequental array of dates
  

  if (dates->getDayOfWeek() != "Sunday"){ //if its not sunday theres a problem bc it has to start on sunday
    cout << "That day is not a Sunday, so we're moving to the nearest future Sunday to start" << endl;
    marchToSunday(dates); //set the first date in the date pointer to the next sunday
    startingDate.setMonth(dates->getMonth()); // reset the starting date
    startingDate.setDay(dates->getDay());
    startingDate.setYear(dates->getYear());
    dates = allocateWeekOfDates(startingDate); //from that new starting date which is a sunday re-allocate the dates 
  }

  cout << "Starting on " << dates->toString() << endl << endl << endl;

  runSeriesSimulation(dates, 7);

  delete[] dates; 

}

Date * PizzaWars::allocateWeekOfDates(Date date){
  Date* datesPtr = new Date[7]; //make a pointer

  datesPtr[0] = date; //set the pointer to point to date

  for (int i = 1; i < 7; i++){
    datesPtr[i] = datesPtr[i-1] + 1; //set the first dateptr date to the starting date and then loop and incroment date
  }

  return datesPtr;
}

void PizzaWars::runSeriesSimulation(Date *dates, int length){

  string winner;
  
  for (int day = 0; day < length; day++) { //loop through a week
    PizzaStore core("Core", 3, 2.0, 0.9); //create pizza store
    PizzaStore schilletter("Schilletter", 6, 1.0, 0.8);
    cout << "Running simulation for " <<  dates[day].getDayOfWeek() << " " << dates[day].toString() << endl << endl << endl;
    winner = runDaySimulation(&dates[day], &core, &schilletter); //get the winner for that day 
    cout << winner << " wins!" << endl << endl << endl;
    if (winner == core.getName()){ //if winner is core then write a log for core
      writeToFile(&dates[day], &core);
    }else if (winner == schilletter.getName()){ 
      writeToFile(&dates[day], &schilletter);
    } else { 
      writeToFile(&dates[day], nullptr); //if its a tie then there should be a null pointer
    }

  }

  //  delete[] dates; i do this in runsimulation
}
string PizzaWars::runDaySimulation(Date *datePtr, PizzaStore* core, PizzaStore* schilletter){
  string winner;
  string TimesWeekends[19] = {"11:00", "11:30", "12:00", "12:30", "1:00", "1:30", "2:00", "2:30", "3:00", "3:30", "4:00", "4:30", "5:00", "5:30", "6:00", "6:30", "7:00", "7:30", "8:00"}; //make a array with the times of the weekend
  string TimesWeekdays[21] = {"11:00", "11:30", "12:00", "12:30", "1:00", "1:30", "2:00", "2:30", "3:00", "3:30", "4:00", "4:30", "5:00", "5:30", "6:00", "6:30", "7:00", "7:30", "8:00", "8:30", "9:00"}; //same but for weekdays
  int time = 0;
  int coreConsumed = 9;
  int schilletterConsumed = 9;
  bool stopCore = false; //should stop the day from running
  bool stopSchilletter = false;
  if(datePtr->getDayOfWeek() == "Saturday" || datePtr->getDayOfWeek() == "Sunday") { //if its a weekend then I know to use the weekend times
    for (double i = 10; i <= 20; i += .5){ //10 is when they open and 20 is when they close so every .5 is equal to a half hour
      usleep(50000);
      cout << TimesWeekends[time] << endl; //print the time
      ++time; //get the next time 
      coreConsumed = rand() % (16); //get a random number between 0 - 15
      coreConsumed += 5; //add 5 to get a random number from 5 - 20
      schilletterConsumed = rand() % (16);
      schilletterConsumed += 5;

      if(!core->consumeSlices(coreConsumed)){ //if this return false then they couldnt eat all the slices so they lose and no one can lose the first run through so setting winner can come after
	stopCore = true;
      }

      if (!schilletter->consumeSlices(schilletterConsumed)){ 
	stopSchilletter = true;
      }
      
      cout << coreConsumed << " slice(s) are consumed at Core" << endl;
      cout << schilletterConsumed << " slice(s) are consumed at Schilletter" << endl;

      cout << "\t\t"; 
      core->showStatus(); //show the current state of the pizza
      cout << "\t ";
      schilletter->showStatus();
      
      winner = "TIE!"; //winner should start as a tie
	
      if (core->getTotalSlicesLeft() > schilletter->getTotalSlicesLeft()) { //if core has more slices left then they win bc they still have pizza to serve
        winner = "Core";
      } else if (schilletter->getTotalSlicesLeft() > core->getTotalSlicesLeft()) { //if schilletter has more then they win
        winner = "Schilletter";
      }
      
      if (stopCore){ //if stop is true then that means core is out of slices and the current winner should be sent back
	return winner;
      }else if(stopSchilletter){ //if stop is true Schilletter is out
	return winner;
      }else if (stopCore && stopSchilletter) { //this means both ran out at the same time so its a tie
	winner = "TIE!";
	return winner;
      }
     
      core->tickUpdate(); //add some pizzas and update the total slices
      schilletter->tickUpdate(); 
      cout << "\t\t";
      core->showStatus(); //show the current state of the pizzas after adding or not
      cout << "\t ";
      schilletter->showStatus();
      cout << endl;
    }
  }
  else { //this is all the same but for a week day
    for (double i = 10; i <= 21; i += .5){
      usleep(50000);
      cout << TimesWeekends[time] << endl;
      ++time;
      coreConsumed = rand() % (16);
      coreConsumed += 5;
      schilletterConsumed = rand() % (16);
      schilletterConsumed += 5;

      
      if(!core->consumeSlices(coreConsumed)){
        stopCore = true;
      }

      if (!schilletter->consumeSlices(schilletterConsumed)){
        stopSchilletter = true;
      }

      cout << coreConsumed << " slice(s) are consumed at Core" << endl;
      cout << schilletterConsumed << " slice(s) are consumed at Schilletter" << endl;

      cout << "\t\t\t";
      core->showStatus();
      cout << "\t\t ";
      schilletter->showStatus();

      winner = "TIE!";

      if (core->getTotalSlicesLeft() > schilletter->getTotalSlicesLeft()) {
        winner = "Core";
      } else if (schilletter->getTotalSlicesLeft() > core->getTotalSlicesLeft()) {
        winner = "Schilletter";
      }

      if (stopCore){ //if stop is true then that means core is out of slices and the current winner should be sent back                                                                                              
        return winner;
      }else if(stopSchilletter){ //if stop is true Schilletter is out                                                                                                                                                
        return winner;
      }else if (stopCore && stopSchilletter) { //this means both ran out at the same time so its a tie                                                                                                               
        winner = "TIE!";
        return winner;
      }

      core->tickUpdate();
      schilletter->tickUpdate();
      cout << "\t\t\t";
      core->showStatus();
      cout << "\t\t ";
      schilletter->showStatus();
      cout << endl;
    }
  }
  
  return winner;
}

void PizzaWars::marchToSunday(Date* datePtr){ //check the current day if its not sunday move to the nexted
 while (!(datePtr->getDayOfWeek() == "Sunday")){
   (*datePtr) = (*datePtr) + 1;
  }
}

void PizzaWars::writeToFile(Date *datePtr, PizzaStore *winner){
  ofstream logFile("log.txt", ios::app); // Open the log file in append mode from c plus plus
  if (logFile.is_open()) { //if its open the continue 
    string dayOfWeek = datePtr->getDayOfWeek(); //just to make my life easer when reading into the file
    string dateStr = datePtr->toString();
    
    if (winner == nullptr) { //if a null is sent in then its a tie
      logFile << left << setw(10) << dayOfWeek << left << setw(10) << dateStr << "Tie!" << endl;
    } else { //if not then print the winner 
      string winnerName = winner->getName();
      int slicesLeft = winner->getTotalSlicesLeft();
      logFile << left << setw(10) << dayOfWeek << left << setw(10) << dateStr << winnerName << " won with " << slicesLeft << " slices left!" << endl;
    }
    
    logFile.close(); // Close the log file
  } else { // if it doesnt get opened then something went wrong
    cout << "Unable to open log file" << endl;
  }
  
}

							 
