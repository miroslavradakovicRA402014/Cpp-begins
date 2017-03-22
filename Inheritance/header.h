#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

enum STATE {HARD,LIQUID,GASEOUS};
enum TYPE {ALCALINE,TERRAALCALINE,WEAK,ACTINOID,LANTANOID,TRANSITION};

class Element {
protected:
  int atomicNumber;
  float atomicMass;
public:
  Element();
  Element(int,float);
  Element(const Element&);

  int getAtomicNumber() const;
  float getAtomicMass() const;

  void print() const;
};

 Element::Element():atomicNumber(0),atomicMass(0){}
 Element::Element(int an,float am):atomicNumber(an),atomicMass(am){}
 Element::Element(const Element& el):atomicNumber(el.getAtomicNumber()),atomicMass(el.getAtomicMass()){}

 int Element::getAtomicNumber() const {
    return atomicNumber;
 }
 float Element::getAtomicMass() const {
    return atomicMass;
 } 

 void Element::print() const {
   cout << "Atomic number :" << atomicNumber << endl;
   cout << "Atomic mass :" << atomicMass << endl;
 }

class Nonmetal : public Element {
private:
  STATE physicalState;
public:
  
  Nonmetal(int,float,STATE);
  Nonmetal(const Nonmetal&);

  STATE getPhysicalState() const;

  void print()const;
};

 Nonmetal::Nonmetal(int an,float am,STATE state):Element(an,am),physicalState(state){}
 Nonmetal::Nonmetal(const Nonmetal& nonm):Element(nonm.getAtomicNumber(),nonm.getAtomicMass()),physicalState(nonm.getPhysicalState()){}

 STATE Nonmetal::getPhysicalState() const {
   return physicalState;
 }

 void Nonmetal::print() const {
    Element::print();
    cout << "Phisycal state :";
    switch (physicalState) {
      case HARD:
        cout << "hard" << endl;
        break;
      case LIQUID:
        cout << "liquid" << endl;
        break;
      case GASEOUS:
        cout << "gaseous" << endl;
        break;
    } 
 }

class Metalloid : public Element {
private:
  bool semiconductor;
public:
  Metalloid(int,float,bool);
  Metalloid(const Metalloid&);

  bool getSemiconductor() const;
 
  void print() const;
};
  
  Metalloid::Metalloid(int an,float am,bool semi):Element(an,am),semiconductor(semi){}
  Metalloid::Metalloid(const Metalloid& metl):Element(metl.getAtomicNumber(),metl.getAtomicMass()),semiconductor(metl.getSemiconductor()){};

  bool Metalloid::getSemiconductor() const {
    return semiconductor;
  }

  void Metalloid::print() const {
    Element::print();
    if (semiconductor) {
      cout << "Semiconductor." << endl;
    } else {
      cout << "Not semiconductor." << endl;
    }
  }


class Metal : public Element {
private:
  float pointOfMelt;
  TYPE typeOfMetal;
public:
  Metal(int,float,float,TYPE);
  Metal(const Metal&); 

  float getPointOfMelt() const;
  TYPE getTypeOfMetal() const;

  void print() const;
};
  
 Metal::Metal(int an,float am,float pm,TYPE type):Element(an,am),pointOfMelt(pm),typeOfMetal(type){};
 Metal::Metal(const Metal& met):Element(met.getAtomicNumber(),met.getAtomicMass()),pointOfMelt(met.getPointOfMelt()),typeOfMetal(met.getTypeOfMetal()){} 

 float Metal::getPointOfMelt() const {
   return pointOfMelt;
 }
 TYPE Metal::getTypeOfMetal() const {
   return typeOfMetal;
 }
 
 void Metal::print() const {
   Element::print();
   cout << "Point of melt :" << pointOfMelt << endl;
   cout << "Type of metal :";
   switch (typeOfMetal) {
     case ALCALINE:
      cout << "alcaline" << endl;
      break;
     case TERRAALCALINE:
      cout << "terraalcaline" << endl;
      break;
     case WEAK:
      cout << "weak" << endl;
      break;
     case LANTANOID:
      cout << "lantanoid" << endl;
      break;
     case ACTINOID:
      cout << "actinoid" << endl;
      break; 
     case TRANSITION:
      cout << "transition" << endl;
      break; 
   }
 }

#endif