#include "header.h"

int main() {

   Metal iron(26,55.84,1200.21,TRANSITION);
   Nonmetal carbon(6,12.01,HARD);
   Metalloid boron(5,10.81,true);

   cout << " Iron " << endl;  
   iron.print();
   cout << endl;

   cout << " Carbon " << endl;
   carbon.print();
   cout << endl;

   cout << " Boron " << endl;
   boron.print();
   cout << endl;

   return 0;
}
