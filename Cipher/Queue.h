/*Cole DiGregorio
CPSC 1071: 888
11/6/2023
Project 3 - Encryption
This programming assignment will require you to implement a variation of a Caesar cipher, where each letter in a message is shifted by a constant amount k. Rather, you will implement a repeating key that uses a series of characters to determine how much each character is shifted.
*/


#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace	std;

class Queue {

  struct QueueNode {      
    char value;
    QueueNode *next;
    QueueNode(char value1, QueueNode *next1 = nullptr)
    {
      value = value1;
      next = next1;
    }
  };
  // These track the front and rear of the queue
  QueueNode *front;
  QueueNode *rear;
  int size;
public:
  // Constructor and Destructor
  Queue();
  ~Queue();
  
  // Member functions
  void enqueue(char);
  void dequeue(char &);
  bool isEmpty() const;
  void clear();
  bool isFull() const;
};

#endif
