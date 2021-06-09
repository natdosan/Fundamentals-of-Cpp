#include <cstdio>
#include <cmath>

class Complex
{
private:
  double _x;
  double _y;

public:
  // Default constructor
  Complex() : _x(0), _y(0)
  {
  }

  // Creating instance
  Complex(double x, double y) : _x(x), _y(y)
  {
  }

  // method 1
  Complex &square(const Complex &c)
  {
    _x *_x == c._x;
    _y *_y == c._y;

    return *this;
  }

  // method 2
  double root()
  {
    return sqrt(_x * _x + _y * _y);
  }

  // method 3
  void dump()
  {
    printf("[%.2lf, %.2lf]\n", _x, _y);
    for (int i = 4.0; i < _x || _y; i++)
    {
      printf("I love 이지은!\n");
    }
  }

  // method 4
  Complex &loop()
  {
    for (int i = 4.0; i <= _x || _y; i++)
    {
      printf("I love 이지은!\n");
    }
    return *this;
  }
};

int main()
{
  Complex c1(5.0, 10.0);
  printf("c1.root() = %.2lf\n", c1.root());
  c1.dump();

  Complex c2{10.0, 20.0};
  printf("c2.root() = %.2lf\n", c2.root());
  c2.dump();
}