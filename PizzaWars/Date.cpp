//Cole DiGregorio                                                                                                                                                                                                     
//C11110105                                                                                                                                                                                                           
//Pizza Wars project

#include "Date.h"
#include "MysteryMachine.h"
#include <iostream>

using namespace std;

int numberOfDaysInMonth(int);

Date::Date() {
  month = 1; //pre-set month
  day = 1; //pre-set day
  year = 2000; //pre-set year 
}

Date::Date(int month, int day, int year){ //set month day and year
  setMonth(month);
  setDay(day);
  setYear(year);
}

int Date::getMonth() { //return objects month 
  return month;
}

int Date::getDay() { //return objects day 
  return day;
}

int Date::getYear(){ //return objects year 
  return year;
}

void Date::setMonth(int m) { //set month 
  month = m;
}
void Date::setDay(int d) { //set day
  day = d; 
}
void Date::setYear(int y){ //set year
  year = y;
}


Date Date::operator+ (int days) {
  Date newDayObject(*this); //create a copy of the object thats being added to 
  newDayObject.day += days; //add the amount that user inputs to the number of days in the new object

  while (newDayObject.day > numberOfDaysInMonth(newDayObject.month)){ //while the day is larger then the number of days in the month in the new object
    newDayObject.day -= numberOfDaysInMonth(newDayObject.month); //subtract off the number of days in the month from the days (if its still larger it will if not then it will return the number of days) 
    newDayObject.month++; //then incroment the month by 1 since the number of days that pasted made the month change
    if (newDayObject.month > 12){ //if the month greater then 12 then it should increase years by 1 since the old year has ended 
      newDayObject.month = 1;
      newDayObject.year++;
    }
  }
  
  return newDayObject; //return the new object that now contains the correct day month and year
}

Date Date::operator- (int days){
  //almost the same as above
  Date newDayObject(*this); //copy object to new object
  newDayObject.day -= days; //subtract the number of days inputed from the current day

  while (newDayObject.day < 1){ //if the number of days is less then 1 theres a problem and should start the loop other wise move on
    newDayObject.month--; //since the number of days is less then 1 that means its the perious month
    if (newDayObject.month < 1){ //if the month is already 1 then it needs to loop back to 12 and it becomes last year
      newDayObject.month = 12; //set to 12 
      newDayObject.year--; //set to last year
    }
    newDayObject.day += numberOfDaysInMonth(newDayObject.month); //add the number of days in the month to the days. If its still less then 1 then it should loop again but if not then it has the correct day 
  }


  //old way of doing it
  
  return newDayObject; //return the new date class that has the correct day month and year
}

Date Date::operator++ (){

  ++day; //add one to the day 

  if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day > 31) { //if the date is 1,3,5,7,8,10 and day is greater then 31 then its the end of the month
    day = 1; //the day goes to 1 from 32
    month++; //add one to the month since the month switched
  }
  else if (month == 12 && day > 31) { //if the month is 12 and the day is greater then 31 then its the end of month and year
    day = 1; //day is set to 1 from 32
    month = 1; //month is set to 1 from 13 
    year++; //year is increased by 1 since its the next year
  }
  else if (month == 2 && day > 28) { // if the month is 2 and the day is greater then 28 then its the end of the month
    day = 1; //day is set to 1 from 29 (TAs said to ignore leap years)
    month++; //increase the month from 2 to 3 
  }
  else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){ // if the month is 4,6,9,10 and the day is greater then 30 then its the end of the month
    day = 1; //day goes to 1 from 31
    month++; //add one to month becuase its the end of the month
  }

  return *this; //return the object by getting this to point to the object
}


Date Date::operator++ (int){

  Date newDateObject(*this); //create a new date object that has the same values as one being incromented so that only the orginal date object is chnaged and the orginal values are returned unchanged
  day++; //add 1 to the day

  if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day > 31) { //if the date is 1,3,5,7,8,10 and day is greater then 31 then its the end of the month
    day = 1; //the day goes to 1 from 32
    month++; //add one to the month since the month switched
  }
  else if (month == 12 && day > 31) { //if the month is 12 and the day is greater then 31 then its the end of month and year
    day = 1; //day is set to 1 from 32
    month = 1; //month is set to 1 from 13
    year++; //year is increased by 1 since its the next year
  }
  else if (month == 2 && day > 28) { // if the month is 2 and the day is greater then 28 then its the end of the month
    day = 1; //day is set to 1 from 29 (TAs said to ignore leap years)
    month++; //increase the month from 2 to 3
  }
  else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){ // if the month is 4,6,9,10 and the day is greater then 30 then its the end of the month
    day = 1; //day goes to 1 from 31
    month++; //add one to month becuase its the end of the month
  }

  return newDateObject; //return the orginal values of the date object and not the changed ones
  
}

Date Date::operator-- (){

  day--; //decroment day by one
  /* 
  if ((month == 5 || month == 7 || month == 12) && day < 1) { //if the month is 3,5,7,8,10,12 and the day is less then 1 then its last month
    day = 30; //make day the last day in the month
    month--; //make the month last month 
  }
  else if (month == 3 && day < 1) { //if the month is 2 and day is less then 1 then its last month 
    day = 28; //make the day the last day in the month 
    month--; //make the month last month 
  }
  else if (month == 1 && day < 1){ //if the month is 1 and day is less then 1 then its month 12 and its last year 
    day = 31; //make day the last day in month 12
    month = 12; //make the month 12
    year--; //make the year last year
  }
  else if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 10 || month == 11) && day < 1){ //if the month is 4,6,9,11 and day is less then 1 that means its last month 
    day = 31; //make day the last day in the month 
    month--; //make it last month
  }
  
  */

   if (day < 1) {
    // Day is less than 1, meaning we need to go back to the previous month
    if (month == 1) {
      // If it's January, set it to December and decrement the year
      month = 12;
      year--;
    } else {
      // For other months, update the month accordingly
      month--;

      if (month == 4 || month == 6 || month == 9 || month == 11) {
        // Handle months with 30 days
        day = 30;
      } else if (month == 2) {
        // Handle February (28 days in non-leap years)
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
          // Leap year (29 days in February)
          day = 29;
        } else {
          // Non-leap year (28 days in February)
          day = 28;
        }
      } else {
        // Handle months with 31 days
        day = 31;
      }
    }
  }
   
  return *this; //return the object by getting this to point to the object
}

Date Date::operator-- (int){

  Date newDateObject(*this); //create a new date object that has the same values as one being incromented so that only the orginal date object is chnaged and the orginal values are returned unchanged
  day--; //decroment the day
  /*
  if ((month == 5 || month == 7 || month == 12) && day < 1) { //if the month is 3,5,7,8,10,12 and the day is less then 1 then its last month
    day = 30; //make day the last day in the month
    month--; //make the month last month
  }
  else if (month == 3 && day < 1) { //if the month is 2 and day is less then 1 then its last month
    day = 28; //make the day the last day in the month
    month--; //make the month last month
  }
  else if (month == 1 && day < 1){ //if the month is 1 and day is less then 1 then its month 12 and its last year
    day = 31; //make day the last day in month 12
    month = 12; //make the month 12
    year--; //make the year last year
  }
  else if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 10 || month == 11) && day < 1){ //if the month is 4,6,9,11 and day is less then 1 that means its last month
    day = 31; //make day the last day in the month
    month--; //make it last month
  }
  */
   if (day < 1) {
    // Day is less than 1, meaning we need to go back to the previous month
    if (month == 1) {
      // If it's January, set it to December and decrement the year
      month = 12;
      year--;
    } else {
      // For other months, update the month accordingly
      month--;

      if (month == 4 || month == 6 || month == 9 || month == 11) {
        // Handle months with 30 days
        day = 30;
      } else if (month == 2) {
        // Handle February (28 days in non-leap years)
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
          // Leap year (29 days in February)
          day = 29;
        } else {
          // Non-leap year (28 days in February)
          day = 28;
        }
      } else {
        // Handle months with 31 days
        day = 31;
      }
    }
  }
  return newDateObject; //return the orginal values of the date object and not the changed ones

}

string Date::getDayOfWeek(){
  MysteryMachine MyM; //make a mystery machine object
  return MyM.getDayOfWeek(*this); //run the getDayOfWeek function in mystery machine taking in this that points to the date object
}

string Date::toString(){
  string monthString = to_string(month); //make the int month to a string 
  string dayString = to_string(day); //make the int day to a string
  string yearString = to_string(year); //make the int year to a string 
  string finalString = monthString + "/" + dayString + "/" + yearString; //string those strings to together (add then to eachother)
  return finalString; //return the final completed string
}

int numberOfDaysInMonth(int month){ //function for knowing how many days are in a partuclar month that is inputed

  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) { //for 1,3,5,7,8,10,12 number of days is 31
    return 31;
  }
  if (month == 4 || month == 6 || month == 9 || month == 11){ //for 4,6,9,11 number of days is 30
    return 30;
  }
  if (month == 2){ //for 2 the number of days is 28 (exculting the leap year)
    return 28;
  }

  return -999; //if its none of these there is a problem so return -999 so that all calculations are clearly off 

}
