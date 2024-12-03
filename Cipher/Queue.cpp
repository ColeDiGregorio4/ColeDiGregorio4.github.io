/*Cole DiGregorio
CPSC 1071: 888
11/6/2023
Project 3 - Encryption
This programming assignment will require you to implement a variation of a Caesar cipher, where each letter in a message is shifted by a constant amount k. Rather, you will implement a repeating key that uses a series of characters to determine how much each character is shifted.
*/
//I used the example from the text book to make my queue class but instead of int i make it to queue chars
#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
  front = nullptr;
  rear = nullptr;
  size = 0;
}

// Destructor

Queue::~Queue()
{
  QueueNode * garbage = front;
  while (garbage != nullptr)
    {
      front = front->next;
      garbage->next = nullptr;
      delete garbage;
      garbage = front;
    }
}

// Function enqueue inserts the value in num at the rear of the queue.
void Queue::enqueue(char num)
{
  if (isEmpty())
    {
      front = new QueueNode(num);
      rear = front;
      ++size;
    }
  else
    {
      rear->next = new QueueNode(num);
      rear = rear->next;
      ++size;
    }
}

// Function dequeue removes the value at the front of the queue, and copies it into num.
void Queue::dequeue(char &num)
{
  QueueNode *temp = nullptr;
  if (isEmpty())
    {
      cout << "The queue is empty.\n";
    }
  else
     {
       --size;
       num = front->value;
       temp = front;
       front = front->next;
       //delete temp; when this is not used my driver doesnt show an error
     }
}

// Function isEmpty returns true if the queue is empty, and false otherwise.
bool Queue::isEmpty() const
{
  if (front == nullptr)
    return true;
  else
    return false;
}

// Function clear dequeues all the elements in the queue.
void Queue::clear()
{
  char value;   // Dummy variable for dequeue
  
  while (!isEmpty()){
    dequeue(value);
  }
}

bool Queue::isFull() const { //additional function to make the queue no larger then 100
  if(size >= 100) {
    return true;
  }
  return false;
}
