#include <iostream>

/*polymorphism: heiarchy of classes related through inheritance
 polymorphism means that a call to a member function will cause a 
 different function to be executed depending on the type of object that invokes the function
*/

// parent class
class Shape
{
protected:
  int width, height;

public:
  // constructor
  Shape(int a = 0, int b = 0)
  {
    width = a;
    height = b;
  }
  int area()
  {
    std::cout << "Parent class area: " << std::endl;
    return 0;
  }
};

class Rectangle : public Shape
{
public:
  Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

  int area()
  {
    std::cout << "Rectangle class area: " << std::endl;
    return (width * height);
  }
};

class Triangle : public Shape
{
public:
  Triangle(int a = 0, int b = 0) : Shape(a, b) {}

  int area()
  {
    std::cout << "Triangle class area: " << std::endl;
    return (width * height / 2);
  }
};

int main()
{
  Shape *shape;
  Rectangle r1(10, 5);
  Triangle t1(10, 5);

  // store the address of the Rectangle
  shape = &r1;
  // store the address of the Triangle
  shape = &t1;

  // call the triangle area
  shape->area();
  return 0;
}
