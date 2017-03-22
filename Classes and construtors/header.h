#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

class Array {
private:
  double* a;
  int n;
public:
  static int objectNum;

  Array();
  Array(int len);
  Array(const Array& arr);

  int getN() const;
  double* getA() const; 
  void setN(int val);
  void setA(double* ptr);
  friend void printArray(const Array& arr);

  ~Array();
};

  Array::Array():a(0),n(0) {
    objectNum++;
    cout << "Non parameter constructor. " << endl;
  }
  Array::Array(int len) {
    cout << "Constructor with parametars." << endl;
    a = new double [len];
    n = len;
    cout << endl;
    for (int i = 0 ; i < len ; i++) {
      cout << "A[" << i << "]=";
      cin >> a[i];
    }
    cout << endl;
    objectNum++;
    //cout << "Constructor with parametars." << endl;
  }
  Array::Array(const Array& arr) {
    cout << "Constructor of copy." << endl;
    a = new double[arr.getN()];
    n = arr.n;
    for (int i = 0; i < arr.getN(); i++) {
     a[i] = arr.a[i];
    }
    objectNum++;
    //cout << "Constructor of copy." << endl;
  }
  
  Array::~Array() {
    delete [] a;
    n = 0;
    a = 0;
    objectNum--;
    cout << "Destructor." << endl;
  }

  int Array::getN() const {
     return n;
  }
  double* Array::getA() const {
     return a;
  }

  void Array::setN(int val) {
     this->n = val;
  }
  void Array::setA(double* ptr) {
     this->a = ptr;
  }

  int Array::objectNum = 0;

  void printArray(const Array& arr) {
    cout << endl;
     
    if (!arr.n) {
      cout << "Empty array!" << endl;
      return;
    }
    for (int i = 0; i < arr.n; i++) {
      cout << "A[" << i << "]=" << arr.a[i] << endl;
    }
    cout << endl;
  }
  
#endif 