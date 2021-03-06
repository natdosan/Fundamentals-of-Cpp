/**
 * Operator overloading review
 * 
 * Copyright (c) 2021, sjkuksee
 */

#include <cstdio>
#include <iostream>

class Complex
{
private:
  double _real;
  double _imaginary;
  friend std::ostream &operator<<(std::ostream &os, const Complex &c);
  friend Complex operator+(const Complex &c1, const Complex &c2);

public:
  Complex(double real, double imaginary) : _real(real), _imaginary(imaginary)
  {
  }

  // sum() adds the instance and returns
  // dont forget const and &
  Complex sum(const Complex &c)
  {
    return Complex(_real + c._real, _imaginary + c._imaginary);
  }

  // overloading the + operator
  // note the const and &
  // when complex is defined inside the class, you only need one param
  Complex operator+(const Complex &c) const
  {
    return Complex(_real + c._real, _imaginary + c._imaginary);
  }

  void dump()
  {
    printf("real, imaginary = ");
    printf("[%.1lf, %.1lf]\n", _real, _imaginary);
  }
};

Complex operator+(const Complex &c1, const Complex &c2)
{
  return Complex(c1._real + c2._real, c1._imaginary + c2._imaginary);
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
  return os << "[" << c._real << ", " << c._imaginary << "]";
}

int main()
{
  Complex c1(2.1, 3.3);
  c1.dump();
  Complex c2(2.1, -3.3);
  c2.dump();

  Complex c3 = c1.sum(c2);
  Complex c4 = c1 + c2; // operator+()
  c4.dump();
}
