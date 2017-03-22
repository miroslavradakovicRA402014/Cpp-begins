#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

class Figure {
public:
  virtual float getSurface()  const = 0  ;
  virtual float getVolume()  const = 0 ;
};

class Rectangle : public Figure {
private:
 float a;
 float b;
public:
 Rectangle();
 Rectangle(float,float);
 Rectangle(const Rectangle&);

 float getA() const;
 float getB() const;

 float getSurface() const;
 float getVolume() const;
};

 Rectangle::Rectangle():a(1),b(1){}
 Rectangle::Rectangle(float pa,float pb):a(pa),b(pb){}
 Rectangle::Rectangle(const Rectangle& rec):a(rec.getA()),b(rec.getB()){}

 float Rectangle::getA() const {
   return a;
 }
 float Rectangle::getB() const {
   return b;
 }

 float Rectangle::getSurface() const {
   return a*b;
 }
 float Rectangle::getVolume() const {
   return 2*(a + b);
 }


class Elipse : public Figure { 
private:
 float x;
 float y;  
public:
 Elipse();
 Elipse(float,float);
 Elipse(const Elipse& el);

 float getX() const;
 float getY() const;

 float getSurface() const;
 float getVolume() const;
 
};

 Elipse::Elipse():x(1),y(1){}
 Elipse::Elipse(float px,float py):x(px),y(py){}
 Elipse::Elipse(const Elipse& el):x(el.getX()),y(el.getY()){}

 float Elipse::getX() const {
   return x;
 }
 float Elipse::getY() const {
   return y;
 }
 
 float Elipse::getSurface() const {
   return x*y*PI;
 }
 float Elipse::getVolume() const {
   return PI*( 3*(x + y) - sqrt((3*x + y)*(3*y + x)) );
 }

class Shape { 
protected:
  Rectangle A;
  Elipse B;
public:
  Shape();
  Shape(float,float);
  Shape(const Shape&);

  float getSurface() const;
  float getVolume() const;

};

 Shape::Shape(){}
 Shape::Shape(float pa,float pb):A(pa,pb),B(pa/2,pb/2){}
 Shape::Shape(const Shape& sh):A(sh.A),B(sh.B){}

 float Shape::getSurface() const {
   float surface = A.getSurface() - B.getSurface();  
   cout << "Surface:" << surface << endl; 
   return surface;
 }
 float Shape::getVolume() const {
   float volume = A.getVolume() + B.getVolume();
   cout << "Volume:" << volume << endl; 
   return volume;
 }

class RegularShape : public Shape {
public:
  RegularShape();
  RegularShape(float);
  RegularShape(const RegularShape& regsh);
};

  RegularShape::RegularShape(){}
  RegularShape::RegularShape(float a):Shape(a,a){}
  RegularShape::RegularShape(const RegularShape& regsh):Shape(regsh.A.getA(),regsh.A.getA()){}

#endif