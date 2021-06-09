/*
*
* Namespaces: a concocted example to show how to use the same name in different spaces without name clash.
*
* copyright (c) sjkuksee
*/

#include <iostream>

// First Color
enum Color
{
  RED,
  GREEN,
  BLUE
};

// Nested namespaces
// Color here has nothing to do with Color above
namespace a
{
  enum Color
  {
    RED,
    BLUE,
    GREEN
  };
  namespace b
  {
    enum Color
    {
      RED,
      GREEN,
      BLUE
    };
  } // namespace b
} // namespace a

int main()
{
  Color c1 = Color::BLUE;

  // Color in the first namespace
  a::Color c2 = a::Color::RED;

  // Second namespace
  a::b::Color c3 = a::b::Color::GREEN;

  std::cout << c1 << ", " << c2 << ", " << c3 << std::endl;
}