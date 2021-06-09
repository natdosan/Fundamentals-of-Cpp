/**
 * Simple factorial recursion
 * 
 * Copyright (c) 2021, sjkuksee
 */

#include <iostream>

int factorial(int n)
{
  // base case, 0! = 1
  if (n <= 0)
    return 1;
  else
    return (factorial(n - 1) * n);
}

int main()
{
  std::cout << factorial(4) << std::endl;
  return 0;
}