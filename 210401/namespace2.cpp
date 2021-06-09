/*
* More common usage of namespaces
*
*
* Copyright (c) 2021, sjkuksee
*/

#include <cstdio>

// Notice no global var
// From file 1, likely developed by developer 1
namespace col
{
  const int size = 0x100;
} // namespace col

// From file 2, likely developed by developer 2
namespace red
{
  const int size = 0x10;
} // namespace red

int main()
{
  printf("col::size = 0x%x, red::size = 0x%x\n", col::size, red::size);
}