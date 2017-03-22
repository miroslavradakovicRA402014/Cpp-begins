#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstring>
using namespace std;

class DinString {
private:
 char* text;
 int length;
public:
 DinString();
 DinString(const char* str);
 DinString(const DinString& str);
 int getLength()const;


 DinString& operator=(const DinString& str);
 DinString& operator+=(const DinString& str);
 friend DinString  operator+(const DinString& str1,const DinString& str2);
 char operator[](int ind);
 char& operator[](int ind)const;
 friend bool operator==(const DinString& str1,const DinString& str2);
 friend bool operator!=(const DinString& str1,const DinString& str2);
 friend ostream& operator<<(ostream& out,const DinString& str);
 
 ~DinString();
};

 DinString::DinString():text(0),length(0) {
  cout << "Constructor without parameters." << endl;
 }
 DinString::DinString(const char* str) { 
  length = 0; 
  while (*(str + length)) {
   length++;
  }  
  text = new char [length+1];
  for (int i = 0; i < length; i++) {
    text[i] = *(str + i);
  }
  text[length] = '\0';
  cout << "Constructor with parametar." << endl;
 }
 DinString::DinString(const DinString& str) {
  length = str.getLength();
  text = new char [str.getLength()+1]; 
  for (int i = 0; i <= length ; i++) {
    text[i] = str[i];
  }
  cout << "Constructor of copy." << endl;
 }
 int DinString::getLength() const{
    return length;
 }
 char DinString::operator[](int ind) {
    return text[ind];
 }
 char& DinString::operator[](int ind)const {
    return text[ind];
 }
 DinString& DinString::operator=(const DinString& str) {
  if (this != &str) {
    delete [] text;    
    text = new char [str.getLength()+1];
    length = str.getLength();
    for (int i = 0; i <= length; i++) {
      text[i] = str[i];
    }
  }
  return *this;
 }
 DinString& DinString::operator+=(const DinString& str) {
   char* temp = new char[length + str.getLength() + 1];
   length = length + str.getLength();
   strcpy(temp,text);
   for (int i = 0; i <= str.getLength(); i++) {
     temp[length + i] = str[i];
   }
   delete [] text;
   text = temp;
   return *this;
 }
 DinString operator+(const DinString& str1,const DinString& str2) {
   char* temp = new char [str1.getLength() + str2.getLength() + 1];
   strcpy(temp,str1.text);
   strcat(temp,str2.text);
   DinString dsTemp(temp);
   return dsTemp;
 }
 bool operator==(const DinString& str1,const DinString& str2) {
    if (str1.getLength() != str2.getLength()) {
      return false;
    } else {
       for (int i = 0; i < str1.getLength();i++) {
         if (str1[i] != str2[i]) {
           return false;
         }
       }
       return true;
    }
 }
 bool operator!=(const DinString& str1,const DinString& str2) {
    return !(str1 == str2);
 }
 ostream& operator<<(ostream& out,const DinString& str) {
    for (int i = 0; i < str.getLength(); i++) {
      out << str[i];
    }
  return out;
 }

 DinString::~DinString() { 
   length = 0;
   delete [] text;
   text = 0;
 }
#endif