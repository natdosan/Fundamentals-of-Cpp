/**
 * Check out list.
 * 
 * 
 * Copyright (c) 2021, sjkuksee
 */

#include <cstdio>
#include "list.h"

// "Macro" to test condition
#define check(b, s) (printf("%s: %s", s, b ? "Pass" : "Fail"))

int main()
{
  List l1;
  check(!l1.contains(100), "contains() should return false on empty");

  // adding one element to the end of node
  l1.append(100);
  check(l1.contains(100), "contains() should be true after add");
  check(!l1.contains(200), "contains() should be false after add");

  l1.append(200);
  check(l1.contains(100), "contains() should be true after add");
  check(l1.contains(200), "contains() should be true after add");
}