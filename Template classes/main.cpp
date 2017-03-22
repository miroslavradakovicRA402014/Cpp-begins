#include "header.h"

int main() {

  Stack<float,5> stackObj;

  stackObj.push(1);
  stackObj.push(2.1);
  stackObj.push(3.2);

  if (!stackObj.empty()) {
   cout << endl <<"Stack size:" << stackObj.size() << endl;
   cout << "Element on top:" << stackObj.top() << endl << endl;
  } else {
   cout << "Stack empty!" << endl;
  }

  stackObj.pop();
  //stackObj.pop();
  //stackObj.pop();
  //stackObj.pop();

  if (!stackObj.empty()) {
   cout << endl << "Stack size :" << stackObj.size() << endl;
   cout << "Element on top :" << stackObj.top() << endl << endl;
  } else {
   cout << "Stack empty!" << endl;
  }

  Stack<float,5> stackObjc;

  stackObjc = stackObj;

  if (!stackObjc.empty()) {
   cout << endl <<"Size of copied stack :" << stackObjc.size() << endl;
   cout << "Element on top of copied stack :" << stackObjc.top() << endl;   
  } else {
   cout << "Stack is empty!" << endl;
  }

  cout << (float)9/2  << endl;
 
  return 0;
}
