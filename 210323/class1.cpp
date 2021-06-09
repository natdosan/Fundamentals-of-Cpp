/**
 * Array of classes
 *
 *
 */

#include <cstdio>

// constants, note the upper case; they are blindly subsituted
#define COUNT 0x100
#define REAL .3
#define IMAGINARY -.7

// "Macro" handled by the "preprocessor"
// Substitute for the function when the logic is simple

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

class Complex
{
private:
  double _real, _imaginary;

public:
  Complex() : _real(0), _imaginary(0)
  {
    // default construct
  }

  Complex(double r, double i) : _real(r), _imaginary(i)
  {
  }
  void dump() const
  {
    printf("[%.2lf, %.2lf]\n", _real, _imaginary);
  }
};

int main()
{
  // array of ints
  int ia1[] = {
      10,
      200,
      -2,
  };

  // not std::vector class
  Complex ca1[] = {
      // defining the array of classes
      Complex(2, 4),
      Complex(-2, .7),
      Complex(1.2, 2.6),
  };

  // Iterate over the complex values in array
  // note the const, & , and : below
  // Scope of "c" is only within the loop !
  for (const Complex &c : ca1)
  {
    c.dump();
  }

  // traditional way of iterating ( do not do )
  for (int i = 0; i < SIZE(ca1); i++)
  {
    ca1[i].dump();
  }

  // pinter to array of Complex with default values
  Complex *ca2 = new Complex[COUNT]; // recall line10

  // Array of Complex with default values
  Complex ca3[COUNT];
  printf("Length of ca3 = %lu\n", SIZE(ca3));

  // clean up (delete the copy)
  delete[] ca2;
}