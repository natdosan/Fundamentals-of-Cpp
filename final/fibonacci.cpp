/**
 * Fibonacci recursion review
 * 
 * copyright (c) 2021, sjkuksee
 */

#include <cstdio>

// O(n^n) time complexity
int fib(int n)
{
  // base case
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

int main()
{
  int n = 10;
  printf("Fibonacci of %d = %d ", n, fib(n));
  return 0;
}