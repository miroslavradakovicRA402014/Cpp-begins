#include "header.h"

int main() {

   DinString string1(" String1 \0");
   DinString string2(" String2 \0");
   DinString string3(string1 + string2);
   DinString string4(string1);
   DinString string5;

   string5 = string2;

   if (string1 == string4) {
     cout << "String1 is equal to String4" << endl;
   } else {
     cout << "String1 is't equal to String4" << endl;
   }

   if (string3 != string5) {
     cout << "String3 is't equal to String5" << endl;
   } else {
     cout << "String3 is equal to String5" << endl;
   }

   cout << endl << string1 << endl << string2 << endl << string3 << endl << string4 << endl << string5; 

   return 0;
}
