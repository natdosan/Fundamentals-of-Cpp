/**
 * Fibonacci using different methods
 * 
 * Copyright (c) 2021, sjkuksee
 */

#include <cinttypes>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#define USAGE "Usage: fib <number> r|m"
#define MAX 255

namespace recursion
{
  //  exponential time comp.
  uint64_t fib(uint8_t n)
  {
    // Base case, do not forget
    if (n <= 1)
    {
      return 1;
    }

    // Recursive step
    return fib(n - 1) + fib(n - 2);
  }
} // recursion

// https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/
namespace memoization
{

  // Using "memoization"
  // Returns 0 if invalid input
  // O(n) time complexity
  uint64_t fibM[MAX];
  uint64_t fib(uint8_t n)
  {
    // input validation
    if (n < 0 || n > MAX)
    {
      return 0;
    }
    for (int i = 1; i <= 2; i++)
    {
      if (fibM[n - i] == 0)
        fibM[n - i] = fib(n - i);
    }
    return fibM[n - 1] + fibM[n - 2];
  }
} // memoization

using namespace recursion;

int main(int argc, char *argv[])
{
  /**  std::cout << "Please input a number";
  int n;
  std::cin >> n;
*/
  // input validation
  if (argc < 3)
  {
    fprintf(stderr, "%s\n", USAGE);
    exit(1);
  }
  uint8_t n = std::atoi(argv[1]);
  uint64_t (*fib)(uint8_t); // This declares a pointer to a function
  if (argv[2][0] == 'r')
  {
    fib = recursion::fib;
  }
  else if (argv[2][0] == 'm')
  {
    fib = memoization::fib;
  }
  else
  {
    fprintf(stderr, "%s\n", USAGE); // Note that errors are sent to stderr
    exit(1);                        // Exits the program with exit code 1
  }
  printf("fib(%d) = %ld\n", n, recursion::fib(n));
}