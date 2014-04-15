#include "slist.hh"

// Part 3
slist& slist::operator=(const slist& o)
{
  // Pointer comparison, no indirection.
  if (this == &o)
    return *this;

  el_t dummy;
  while (!this->isEmpty())
    this->deleteRear(dummy);
  for (Node *n = o.Front; n != nullptr; n = n->Next)
    this->addRear(n->Elem);

  return *this;
}

bool slist::operator==(const slist& o)
{
  if (Count != o.Count)
    return false;
  // on is of type Node (stupid language), that's why we need "*on".
  for (Node *n = Front, *on = o.Front; n != nullptr && on != nullptr; n = n->Next, on = on->Next)
    if (n->Elem != on->Elem)
      return false;
 return true;
}

// Just defer to the assignment operator.
slist::slist(const slist& o)
{
  Front = nullptr;
  Rear = nullptr;
  Count = 0; // Zero
  *this = o;
}



// Old stuff: Part 2

slist::slist() {}

int	slist::search(el_t k)
{
  Node*	n = this->Front;
  int	fidx = 1;
  do {
    if (n->Elem == k)
      return fidx;
    n = n->Next;
    ++fidx;
  } while (n != nullptr);
  return 0;
}

void	slist::replace(el_t e, int idx)
{
  if (idx > this->Count)
    throw new OutOfRange();
  Node*	n = this->Front;
  while (idx-- > 1)
    n = n->Next;
  n->Elem = e ;
}
