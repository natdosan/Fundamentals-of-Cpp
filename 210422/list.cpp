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

void List::init(int val[], int n)
{
  for (int i = 0; i < n; i++)
  {
    append(val[i]);
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

// remove() locates the first element with a given value and deletes it
// takes no action if not found
bool List::remove(int n)
{
  // check if empty
  if (_head == nullptr)
    return false;

  // check the head
  if (_head->_value == n)
  {
    // hold on to/save the head
    Node *dp = _head;
    // found the value in head, update it, then delete
    _head = _head->_next;
    // update the tail in the case that there is only one element
    if (_head == nullptr)
    {
      _tail = nullptr;
    }
    delete dp;
    return true;
  }
  // check the remaining list
  // create a pointer to the head, as long as current head is not null, move the head value to the next node
  for (Node *np = _head; np->_next != nullptr; np = np->_next)
  {
    // if we find a value in the nodes that matches the one we want to remove
    if (np->_next->_value == n)
    {
      Node *dp = np->_next;
      np->_next = np->_next->_next;
      // if the next node is the last element, we have to make the tail update to the current node
      if (np->_next == nullptr)
      {
        _tail = np;
      }
      delete dp;
      return true;
    }
  }
  return false;
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