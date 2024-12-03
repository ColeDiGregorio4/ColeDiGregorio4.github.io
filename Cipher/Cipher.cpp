/*Cole DiGregorio
CPSC 1071: 888
11/6/2023
Project 3 - Encryption
This programming assignment will require you to implement a variation of a Caesar cipher, where each letter in a message is shifted by a constant amount k. Rather, you will implement a repeating key that uses a series of characters to determine how much each character is shifted.
*/



#include "Cipher.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getLetterNumber(char); //getting the value of a letter not global just a function prototype
char getLetter(int); //getting the letter from the value not global just a function prototype

Cipher::Cipher() {
  key = (char*)"cpsc"; //set default key 
  setCipher(4, key); //set default cipher
}

Cipher::Cipher(int keySize, char* key) {
  key = key; //set the key
  setCipher(keySize, key); //set the cipher
}

void Cipher::setCipher(int keySize, char* key) {
  char temp;
  if (keySize < 0 || key == nullptr) { //if there is key then there is a problem
    throw invalid_argument("Invalid key size or key is null."); //throw a error
  } else {
    for (int i = 0; i < keySize; i++) { //cycle through the key
      if(isspace(key[i]) || isdigit(key[i]) || key[i] == '.' || key[i] == '!' || key[i] == '?' || key[i] == ',' || key[i] == '$' || key[i] == ';' || key[i] == ':' || key[i] == '@'){ //do nothing if there are digits or special chars
      }
      else if (isalpha(key[i])) { //got from c plus plus and if there is a capital letter
	temp = tolower(key[i]); //make it lower case also got from c plus plus
	queueKey.enqueue(temp); //loop through the key and add each char to a queue
      }
      else {
	queueKey.enqueue(key[i]); //add that char to the key
      }
    }
    this->key = key; //used for get cipher
    cout << endl;
  }
}

  
char* Cipher::getCipher(){
  return &key[0]; //send the key back
}

string Cipher::encodeMessage(const string& message) {
  string encodedMessage;
  char currentChar;
  char keyChar;
  char shiftedChar;
  //copy queue
  Queue copyKeyQueue = queueKey; //make a copy of the queue so previous encoding or decoding doesnt mess up the key order
  if (copyKeyQueue.isEmpty()) { //if the queue is empty throw a problem
    throw invalid_argument("Invalid key is empty");
  } else {
    for (int i = 0; i < message.size(); ++i) { //loop through message
      if(isspace(message[i]) || isdigit(key[i]) || key[i] == '.' || key[i] == '!' || key[i] == '?' || key[i] == ',' || key[i] == '$' || key[i] == ';' || key[i] == ':' || key[i] == '@'){ //same as above
	//do nothing
      }else if(!isalpha(message[i])){ //same as above with checking the key for capitals
	currentChar = tolower(message[i]); //set the temp char to a lower case
	copyKeyQueue.dequeue(keyChar); //get the top of the queue char
	shiftedChar = letterShift(currentChar, keyChar, false); //the shifted char is the char returned after shifting to the new letter
	encodedMessage += shiftedChar; //add the char to the message
	queueKey.enqueue(keyChar); //put the top back incase it has to loop
      } else {
	currentChar = message[i]; //same as above but without changing the capital
	copyKeyQueue.dequeue(keyChar);
	shiftedChar = letterShift(currentChar, keyChar, false);
	encodedMessage += shiftedChar;
	queueKey.enqueue(keyChar);
      }
    }
  }
  return encodedMessage; //send the message back
}

string Cipher::decodeMessage(const string& encodedMessage) {

  //same code as above excpet you put true for letter shift so it does it in reverse
  string decodedMessage;
  char currentChar;
  char keyChar;
  char shiftedChar;
  Queue copyKeyQueue = queueKey;
  if (copyKeyQueue.isEmpty()) { 
    throw invalid_argument("Invalid key is empty");
  } else {
    for (int i = 0; i < encodedMessage.size(); ++i) {
      if(isspace(encodedMessage[i]) || isdigit(key[i]) || key[i] == '.' || key[i] == '!' || key[i] == '?' || key[i] == ',' || key[i] == '$' || key[i] == ';' || key[i] == ':' || key[i] == '@'){
       
      }else if(isalpha(encodedMessage[i])){
        currentChar = tolower(encodedMessage[i]);
        copyKeyQueue.dequeue(keyChar);                               
        shiftedChar = letterShift(currentChar, keyChar, true);           
        decodedMessage += shiftedChar;                               
        queueKey.enqueue(keyChar);                            
      } else {
        currentChar = encodedMessage[i];
        copyKeyQueue.dequeue(keyChar);
        shiftedChar = letterShift(currentChar, keyChar, true);
        decodedMessage += shiftedChar;
        queueKey.enqueue(keyChar);
      }
    }
  }
  return decodedMessage; 
}

char Cipher::letterShift(char l1, char l2, bool reverse) {
  int timesShifted = getLetterNumber(l2); //get the number of times you have to shift
  int orginalLetterValue = getLetterNumber(l1); //get the orginal number value of the letter
  int newLetterValue = 0; 
  char result;
  if (reverse == false){ //if you are encoding a message
    if ((timesShifted + orginalLetterValue) > 26){ //if there if the new letter value is greater then 26 then it should start back at the top of the abc's
      newLetterValue = (timesShifted + orginalLetterValue) - 26; //set the letter to loop the abc's
    }else{
      newLetterValue = timesShifted + orginalLetterValue; //set the new letter value to the value of the shifted letter value  
    }
    result = getLetter(newLetterValue); //get the new letter
    return result; //return the new letter
  }else { //for decode
    if((orginalLetterValue - timesShifted) <= 0){ //if the letter value is now 0 or negitive 
      newLetterValue = (orginalLetterValue - timesShifted) + 26; //same logic as above to loop through the abc's
      result = getLetter(newLetterValue); //set the result as the new letter that corilates with its value
      return result;
    }else {
      newLetterValue = orginalLetterValue - timesShifted; //if we are decoding it is the same procress but backwards
      result = getLetter(newLetterValue); //same as above
      return result;
    }
  }
}

//this is so i can get the value of the letter
int getLetterNumber(char letter){
  switch(letter) {
  case 'a':
      return 1;
  case 'b':
      return 2;
  case 'c':
      return 3;
  case 'd':
      return 4;
  case 'e':
      return 5;
  case 'f':
      return 6;
  case 'g':
      return 7;
  case 'h':
      return 8;
  case 'i':
      return 9;
  case 'j':
      return 10;
  case 'k':
      return 11;
  case 'l':
      return 12;
  case 'm':
      return 13;
  case 'n':
      return 14;
  case 'o':
      return 15;
  case 'p':
      return 16;
  case 'q':
      return 17;
  case 'r':
      return 18;
  case 's':
      return 19;
  case 't':
      return 20;
  case 'u':
      return 21;
  case 'v':
      return 22;
  case 'w':
      return 23;
  case 'x':
      return 24;
  case 'y':
      return 25;
  case 'z':
      return 26;
  default:
    return 0;
  }
}
//this is so i can take a value and return a letter
char getLetter(int letterNumber){
  switch(letterNumber) {
  case 1:
      return 'a';
  case 2:
    return 'b';
  case 3:
      return 'c';
  case 4:
      return 'd';
  case 5:
      return 'e';
  case 6:
      return 'f';
  case 7:
      return 'g';
  case 8:
      return 'h';
  case 9:
      return 'i';
  case 10:
      return 'j';
  case 11:
      return 'k';
  case 12:
      return 'l';
  case 13:
      return 'm';
  case 14:
      return 'n';
  case 15:
      return 'o';
  case 16:
      return 'p';
  case 17:
      return 'q';
  case 18:
      return 'r';
  case 19:
      return 's';
  case 20:
      return 't';
  case 21:
      return 'u';
  case 22:
      return 'v';
  case 23:
      return 'w';
  case 24:
      return 'x';
  case 25:
      return 'y';
  case 26:
      return 'z';
  default:
    return '0';
  }
}

