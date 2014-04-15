// ====================================================
// HW3P1 llist
// Your name: Mathias LANG
// Compiler:  g++
// File type: Linked list implementation file
//=====================================================

#include	<iostream>
#include	"llist.hh" 

llist::llist() : Front(NULL), Rear(NULL), Count(0)	{}

llist::~llist()
{
  // Is only used to call deleteFront, value is not used.
  el_t dummy;
  std::cout << "Calling the llist destructor." << std::endl;
  while (!isEmpty())
    deleteFront(dummy);
}

bool	llist::isEmpty() const
{
  return (this->Front == this->Rear
	  && this->Front == NULL);
}

void	llist::displayAll() const
{
  // Special case: if the list is empty, display "[ Empty ]".
  if (isEmpty()) {
    std::cout << "[ Empty ]" << std::endl;
  } else {
    // Used to iterate over the list.
    Node*	curr = this->Front;
    // Displays each element of the list starting from Front in [ ].
    do {
      std::cout << "[" << curr->Elem << "]" << std::endl;
      curr = curr->Next;
    } while (curr != NULL);
  }
}

void llist::addRear(el_t NewNum)
{
  if (isEmpty())	// Special case: First node
    this->Front = this->Rear = new Node;
  else {		// Regular case
    this->Rear->Next = new Node();
    this->Rear = this->Rear->Next;
  }
  this->Rear->Elem = NewNum;
  this->Rear->Next = NULL;
  ++this->Count;
}

void llist::deleteFront(el_t& OldNum)
{
  if (isEmpty())
    throw new Underflow();
  OldNum = this->Front->Elem;
  // This is just a temp variable.
  Node*	toDel = this->Front;
  this->Front = this->Front->Next;
  // Special case: The list only had 1 elem.
  if (this->Front == NULL)
    this->Rear = NULL;
  delete toDel;
  --this->Count;
}

void llist::addFront(el_t NewNum)
{
  // Temporary variable to hold front.
  Node*	newFront;
  if (isEmpty()) {	// Special case: First node
    this->Front = this->Rear = new Node;
    this->Front->Next = NULL;
  } else {		// Regular case
    newFront = new Node();
    // In case we only have one item in the list.
    newFront->Next = this->Front;
    this->Front = newFront;
  }
  this->Front->Elem = NewNum;
  ++this->Count;
}

void llist::deleteRear(el_t& OldNum)
{
  if (isEmpty())
    throw new Underflow();
  OldNum = this->Rear->Elem;

  // Special case for 1-elem list
  if (this->Rear == this->Front)
    return deleteFront(OldNum);

  // This is just a temp variable used to find the new rear.
  Node*	newRear = this->Front;
  while (newRear->Next != this->Rear)
    newRear = newRear->Next;

  delete this->Rear;
  this->Rear = newRear;
  this->Rear->Next = NULL;
  --this->Count;
}

void llist::deleteIth(int I, el_t& OldNum)
{
  // Special cases: Invalid value
  if ((I < 1) || (I > this->Count))
    throw new OutOfRange();

  // Special cases: Delete front / rear
  if (I == 1)
    return deleteFront(OldNum);
  if (I == this->Count)
    return deleteRear(OldNum);

  // By now we are left only with a list of Count > 1, and valid data.
  // Those pointers old references to the previous and current item to iterate.
  Node*	prev = this->Front;
  Node* curr = this->Front->Next;
  while (--I > 1) {
    prev = curr;
    curr = curr->Next;
  }
	
  prev->Next = curr->Next;
  OldNum = curr->Elem;
  delete curr;
  --this->Count;
}

void llist::addbeforeIth(int I, el_t newNum)
{
  // Special cases: Invalid value
  if (I < 1 || (I > (this->Count + 1)))
    throw new OutOfRange();

  // Special cases: Add front / rear
  if (I == 1)
    return addFront(newNum);
  if (I == (this->Count + 1))
    return addRear(newNum);

  // By now we are left only with a list of Count > 1, and valid data.
  // Those pointers old references to the previous and current item to iterate.
  Node*	prev = this->Front;
  Node* curr = this->Front->Next;
  while (--I > 1) {
    prev = curr;
    curr = curr->Next;
  }
	
  prev->Next = new Node;
  prev->Next->Next = curr;
  prev->Next->Elem = newNum;
  ++this->Count;
}
