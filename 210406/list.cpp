/**
 * List implimentation
 * 
 * 
 * copyright (c) 2021, sjkuksee
 */

#include "node.h"
#include "list.h"

List::List() : _head(nullptr), _tail(nullptr)
{
}

List::~List()
{
  // deallocate nodes
}

void List::append(int v)
{
  // created on the heap, will exist after the function returns
  // Never use an "automatic" variable; they wont be put on the stack
  //
  Node *np = new Node(v);

  // Always check for nullptr; here list is empty
  // assigning to both head and tail
  if (_head == nullptr)
  {
    _head = _tail = np;
    return;
  }

  // Not empty, means neither head nor tail can be null
  // What is happening here?
  _tail->_next = np;    //  assigning tail to point to the "link"
  _tail = _tail->_next; // tail is equal to the tail of the "next" pointer of the following node
}

// looks for given value, return true/false
bool List::contains(int v)
{
  // Iteration following the pointers
  for (Node *np = _head; np != nullptr; np = np->_next)
  {
    if (np->_value == v)
    {
      return true;
    }
  }
  return false;
}
