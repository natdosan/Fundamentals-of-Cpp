/**
 * List data structure
 * 
 * 
 * Copyright (c) 2021, sjkuksee
 */

#ifndef LIST_H_
#define LIST_H_

#include "node.h"

// Data structure implemented by class
class List
{
private:
  Node *_head;
  Node *_tail;

public:
  List(/* args */);
  ~List();
  void init(int[], int);
  void append(int);   // Add element at the end
  bool contains(int); // returns true if in the list
  void insert(int, int);
  bool remove(int);
  void dump();
};

#endif // LIST_H_