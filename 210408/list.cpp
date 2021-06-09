/**
 * List implimentation
 * 
 * 
 * copyright (c) 2021, sjkuksee
 */

#include <cstdio>
#include "node.h"
#include "list.h"

List::List() : _head(nullptr), _tail(nullptr)
{
}

List::~List()
{
  // deallocate nodes
  // Must check for null, also do NOT do np = np->next in loop header
  for (Node *np = _head; np != nullptr;)
  {
    Node *cnp = np; // copy so we can delete later
    np = np->_next; // OK because we know np is not null
    delete cnp;
  }
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
  _tail = _tail->_next; // assigning tail to
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

// inserts given value v after the first node whose value is n.
// If list is empty, add to list
// if n is not found, add at the end
void List::insert(int n, int v)
{
  // Sad/happy path constructs make code easy to read, have less nesting
  if (_head == nullptr)
  {
    append(v);
    return;
  }

  // Precondition: _head is NOT NULL
  // We also know from the list logic that _tail is also not null

  Node *nnp = new Node(v);
  for (Node *np = _head; np != nullptr; np = np->_next)
  {
    if (np->_value == n)
    {
      nnp->_next = np->_next; // Safe because we checked np != null
      np->_next = nnp;
      if (np == _tail)
      {
        _tail = _tail->_next;
      }
      return;
    }
  }
  _tail->_next = nnp; // Safe because we know tail != null
  _tail = _tail->_next;
}

// display all the elements in list
void List::dump()
{
  for (Node *np = _head; np != nullptr; np = np->_next)
  {
    if (np != _head)
    {
      printf("->");
    }
    printf("%d", np->_value);
  }
  printf("\n");
}