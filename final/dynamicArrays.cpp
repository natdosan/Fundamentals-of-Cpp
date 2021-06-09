/**
 * Dynamic Arrays and pointers
 * 
 * copyright (c) 2021, sjkuksee
 */

#include <iostream>

typedef int *rating;

int main()
{
  rating r;
  int a[10];

  for (int i = 0; i < 10; i++)
  {
    a[i] = i;
  }

  // an array is a kind of pointer variable
  r = a;

  for (int i = 0; i < 10; i++)
  {
    std::cout << r[i] << " ";
    std::cout << std::endl;
  }

  for (int i = 0; i < 10; i++)
  {
    r[i] = r[i] + 1;
  }

  for (int i = 0; i < 10; i++)
  {
    std::cout << a[i] << " ";
    std::cout << std::endl;
  }
}