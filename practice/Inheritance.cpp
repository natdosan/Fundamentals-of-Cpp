#include <iostream>

// base class
class Shape
{
protected:
  int _width;
  int _height;

public:
  void setWidth(int w)
  {
    _width = w;
  }
  void setHeight(int h)
  {
    _height = h;
  }
};

// inherits width and height
// "derived" class
class Rectangle : public Shape
{
public:
  int getArea()
  {
    int area = (_width * _height);
    return area;
  }
};

int main()
{
  Rectangle r1;
  r1.setWidth(5);
  r1.setHeight(10);
  r1.getArea();

  printf("%.1d", r1.getArea());

  return 0;
}