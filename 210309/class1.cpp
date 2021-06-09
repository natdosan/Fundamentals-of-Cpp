#include <cstdio>

// Class name starts with an upper case
class Complex
{
private:
    // This is the "data" part
    double _real;
    double _imaginary;

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

    // "Operations" on the private date, a key tenet of "informational cohesion"
    void dump()
    {
        printf("%.1lf, %.1lf\n", _real, _imaginary);
    }
};

int main()
{
    // "Instantiation" of the class
    // reads to line 18
    Complex c1(2.0, 3.0);
    Complex c2 = {1.0, 4.0};
    Complex *c3p = new Complex(3.0, 2.0); // Dynamic allocation, returns the pointer
    c1.dump();
    c2.dump();
    c3p->dump(); // note the -> notation for a pointer

    // Using the default constructor
    // reads to line 13
    Complex c4; // NOT "Complex c4();"
    c4.dump();

    // Alwasy delete allocated memory!
    // Remember C++ is NOT "garbage collected"
    delete c3p;
}