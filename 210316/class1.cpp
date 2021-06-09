#include <cstdio>
#include <cmath>

class Complex
{
private:
  double _real;
  double _imaginary;

  // recommended location (inside priv)
  // prototype must exactly match
  // Don't use it unless you must
  friend void dump(const Complex &);

public:
  // "Default" constructor, required because there is another constructor
  Complex() : _real(0), _imaginary(0)
  {
    // initialized
  }

  // "Constructor" to create an "instance" of the class
  Complex(double real, double imaginary) : _real(real), _imaginary(imaginary)
  {
  }

  void add(const Complex &c) // call by reference
  {
    _real += c._real;
    _imaginary += c._imaginary;
  }

  void multiply(const Complex &c)
  {
    _real *= c._real;
    _imaginary *= c._imaginary;
  }

  // This is another method
  double value()
  {
    return sqrt(_real * _real + _imaginary * _imaginary);
  }

  void dump(const Complex &c) // const & to avoid making a copy and changing the file
  {
    printf("[%.1lf, %.1lf]\n", c._real, c._imaginary);
  }
};

int main()
{
  Complex c1(2.0, 3.0);
  printf("c1.value() = %.1lf\n", c1.value());
  dump(c1);

  Complex c2 = {1.0, 4.0};
  printf("c2.value() = %.1lf\n", c2.value());
  dump(c2);

  c1.add(c2);
  dump(c1);

  c1.multiply(c2);
  dump(c2);
}