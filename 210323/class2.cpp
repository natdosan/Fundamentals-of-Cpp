/**
 * Destructors.
 *
 * Copyright (c), Nathaniel del Rosario
 */

#include <cstdio>

#define COUNT 2

class Complex
{
private:
  double _real, _imaginary;

public:
  Complex() : _real(0), _imaginary(0)
  {
  }
  Complex(double r, double i) : _real(r), _imaginary(i)
  {
  }
  void dump()
  {
    printf("[%.1lf, %.1lf]\n", _real, _imaginary);
  }
};

class List
{
private:
  int _size = 0; // initializes to 0 for all instances by default
  int _max;
  Complex *_values; // new object of Complex::Complex

public:
  // anytime you allocate memory, you must delete it somewhere
  // this is often done in the "destructor"
  explicit List(int n) : _max(n), _values(new Complex[n])
  {
    // typical purpose of this destructor si to clean up resources, like memory
  }
  ~List()
  {
    printf("~List() called, deleting memory...\n");
    delete[] _values;
  }
  void add(Complex c)
  {
    // "Sad" path
    if (_size == _max)
      return;

    // happy path
    // ++ works here becasue it is a "post" operation
    _values[_size++] = c;
  }

  Complex *values()
  {
    return _values;
  }
};

int main()
{
  List l1(COUNT);
  l1.add(Complex(3, 2));
  l1.add(Complex(3, 2));
  l1.add(Complex(4.2, 7.2));

  // "auto" keyword figures out the type at compile time
  // Could have also defiend this as Complex *values = l1.values()
  // Always assign results of funciton calls to local variavle (for efficiency)

  auto values = l1.values();
  for (int i = 0; i < COUNT; i++)
  {
    values[i].dump();
  }
}