/*Cole DiGregorio
CPSC 1071: 888
11/6/2023
Project 3 - Encryption
This programming assignment will require you to implement a variation of a Caesar cipher, where each letter in a message is shifted by a constant amount k. Rather, you will implement a repeating key that uses a series of characters to determine how much each character is shifted.
*/

#include "Queue.h" 
#include "Cipher.h"
#include <iostream>
#include <cstring> //used for get line from c plus plus
using namespace std;

int main() {
  string keyString;
  
  cout << "Type in the word to use as the key: ";
  getline(cin, keyString); //get line is used so that when the user inputs a key they can have spaces in it

  char key[keyString.length() + 1]; //setting the key char to the length of the key string + 1

  strcpy(key, keyString.c_str()); //using c plus plus to convert the key car array to a pointer that points to the key string
  Cipher cipher(keyString.length(), key); //set the cipher object
  char userInput = 'f';
  string userInputString;
  string encodeMessage;
  string decodeMessage;
  string encoded;
  string decoded;
  
  while (userInput != 'q'){ //run menu until quit
    cout << "Key: " << cipher.getCipher() << endl; //print out the key 
    cout << "[e] encode with that key" << endl;
    cout << "[d] decode with that key" << endl;
    cout << "[q] quit" << endl;
    cin >> userInputString;
    if (userInputString.length() > 1){ //if the string is greater then one then its invaild
      userInput = 'f';
    }else{
      userInput = userInputString[0]; //get the frist char of the string
      if (isdigit(userInput)){ //if its a digit its invalid
	userInput = 'f';
      }			   
    }
    
    switch (userInput) {
    case 'e':
      cout << "Enter what to encode: ";
      cin.ignore();
      getline(cin, encodeMessage); //same reason as above for get line
      encoded = cipher.encodeMessage(encodeMessage); //encode message
      cout << "result: " << encoded << endl;
      break;
    case 'd':
      cout << "Enter what to decode: ";
      cin.ignore();
      getline(cin, decodeMessage); //^^
      decoded = cipher.decodeMessage(decodeMessage); //decode a message
      cout << "result: " << decoded << endl;
      break;
    case 'q':
      break;
    default:
      cout << "Invalid choice. Try again." << endl;
    }
  }
  
  return 0;
}
