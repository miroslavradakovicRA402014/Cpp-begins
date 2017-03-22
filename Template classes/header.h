#ifndef HEADER_H
#define HEADER_H
#define MAX_SIZE 20
#include <iostream>
using namespace std;

template<typename TYPE,int cap>
class Stack {
private:
  TYPE* stack;
  TYPE* stackPointer;
  int stackSize;
  int capacity;
public:
  Stack();

  //TYPE* getStack() const;

  Stack<TYPE,cap>& operator=(const Stack<TYPE,cap>& );
  void push(TYPE);
  TYPE pop();
  TYPE top() const;
  int size() const;
  bool empty() const;  

  ~Stack();
};

template<typename TYPE,int cap>
Stack<TYPE,cap>::Stack():capacity(cap),stackPointer(0),stackSize(0) {
 if (capacity <= MAX_SIZE && capacity > 0) {
  stack = new TYPE [capacity];
  stackPointer = 0;
 } else { 
  cout << "Can't create stack of this size!" << endl;
 }
}

template<typename TYPE,int cap>
bool Stack<TYPE,cap>::empty() const {
  if (stackPointer == stack) {
    return true;
  } else {
    return false;
  }
}

template<typename TYPE,int cap>
int Stack<TYPE,cap>::size() const {
   return stackSize;
}


template<typename TYPE,int cap>
void Stack<TYPE,cap>::push(TYPE el) {
 if (stackSize <= capacity) {
   stackPointer = (stackSize == 0)? stack : stackPointer + 1;
   *stackPointer = el;
   stackSize++;
 } else {
   cout << "Stack's full can't push element!" << endl;
 }
}

template<typename TYPE,int cap>
TYPE Stack<TYPE,cap>::pop() {
 if (empty()) {
   cout << "Stack's empty can't pop element!" << endl;
 } else {
   TYPE el = *stackPointer;
   stackPointer = (stackSize == 0)? 0 : stackPointer - 1;
   stackSize--;
   return el;
 }
}

template<typename TYPE,int cap>
TYPE Stack<TYPE,cap>::top() const {
 if (empty()) {
   cout << "Stack's empty can't approach top element!" << endl;
   return -1;
 } else {
   TYPE el = *stackPointer;
   return el;
 }
}

template<typename TYPE,int cap>
Stack<TYPE,cap>::~Stack() {
   stackSize = 0;
   delete [] stack;
   stack = 0;
   stackPointer = 0;
}

template<typename TYPE,int cap>
Stack<TYPE,cap>& Stack<TYPE,cap>::operator=(const Stack<TYPE,cap>& sta) {
  if (&sta != this ) {
   stackSize = sta.stackSize;
    if (stackSize != 0) {
     stackPointer = stack;
     for (int i = 0; i < stackSize; i++,stackPointer++) {
       *(stackPointer + i) = *(sta.stack + i);
     }
    } else {
     stackPointer = 0;
    }    
  }
  return *this; 
}
/*
template<typename TYPE,int cap>
TYPE* Stack<TYPE,cap>::getStack() const {
  return stack;
}
*/
#endif