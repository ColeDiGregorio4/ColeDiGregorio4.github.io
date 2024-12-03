#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date { // defaults to Jan 1st, 2000
 public:
  Date();
  Date(int month, int day, int year); //overloaded operator

  int getMonth(); // accessors
  int getDay();
  int getYear();

  void setMonth(int month); // mutators
  void setDay(int day);
  void setYear(int year);

  Date operator+(int days); // overloaded operators
  Date operator-(int days);
  Date operator++(void); // prefix
  Date operator++(int); // postfix
  Date operator--(void); // prefix
  Date operator--(int); // postfix

  string getDayOfWeek(); // implements the mystery machine
  string toString(); // string form in mm/dd/yyyy

 private:
  int month;
  int day;
  int year;
};
#endif
