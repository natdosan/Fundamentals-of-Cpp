/**
 * Pointer review
 * 
 * copyright (c) 2021, sjkuksee
 */

#include <string>
#include <iostream>

using namespace std;

int main()
{
  std::string *p1, *p2;

  p1 = new std::string;
  *p1 = "Sana";
  p2 = p1;
  cout << "*p1 == " << *p1 << endl; // Sana
  cout << "*p2 == " << *p2 << endl; // Sana
  *p2 = "Monday";
  cout << "*p1 == " << *p1 << endl; // Monday
  cout << "*p2 == " << *p2 << endl; // Monday
  p1 = new std::string;
  *p1 = 88;
  cout << "*p1 == " << *p1 << endl; // X
  cout << "*p2 == " << *p2 << endl; // Monday
}