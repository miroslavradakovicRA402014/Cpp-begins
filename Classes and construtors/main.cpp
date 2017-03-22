#include "header.h"

int main() {

  Array arr1,arr2(4),arr3(arr2);
  cout << "Number of objects :" << Array::objectNum << endl;

  printArray(arr1);
  printArray(arr2);
  printArray(arr3);

  return 0;
}
