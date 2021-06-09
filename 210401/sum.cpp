/* 
* Summing Utility
*
* copyright (c) 2021, sjkuksee
*
*/

// "Global" variables, NEVER use
// int size = 100;

// inside an unnamed namespace is OK
namespace
{
  int size = 1000;
}

// Sumas all integers from 1 to given n
// 0 <= n <= 1000
int sum(int n)
{
  int s = 0;

  // Always impliment a "Sad path" that checks validity first
  if (n > size)
  {
    return s;
  }
  for (int i = 1; i <= n; i++)
  {
    return s += i;
  }
  return s;
}