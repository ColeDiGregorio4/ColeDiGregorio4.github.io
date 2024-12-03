/*Cole DiGregorio
CPSC 1071: 888
11/11/2023
Project 3 - Encryption
This programming assignment will require you to implement a variation of a Caesar cipher, where each letter in a message is shifted by a constant amount k. Rather, you will implement a repeating key that uses a series of characters to determine how much each character is shifted.
*/


#ifndef CIPHER_H
#define CIPHER_H
#include <string>
#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;

class Cipher {
public:
  Cipher();
  Cipher(int keySize, char* key);
  void setCipher(int keySize, char* key);
  char* getCipher();
  string encodeMessage(const string& message);
  string decodeMessage(const string& encodedMessage);
  static char letterShift(char l1, char l2, bool reverse);
  char* key;
  Queue queueKey;
};

#endif
