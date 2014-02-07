// =========================================================
//HW1P1 queue
//Your name: Mathias LANG
//Complier:  g++
//File type: source file queue.cpp

//================================================================

#include	<iostream>
#include	<cstdlib>
#include	"queue.h"

int	queue::incr(int currVal)
{
  return ((currVal + 1 >= MAX_SIZE)
	  ? (0)
	  : (currVal + 1)
	  );
}

int	queue::nextElem(int currVal)
{
  // If the incr makes us go past MAX_SIZE,
  // we check what is the next element.
  // If currVal is after front, then the next
  // element is front.
  // if currVal is front, then the next element is 0.
  if ((currVal + 1) >= MAX_SIZE) 
    return ((this->front == currVal)
	    ? (0)
	    : (this->front));
  return currVal + 1;
}

// constructor 
queue::queue() : count(0), front(0), rear(0)  {}

//destructor 
queue::~queue() {}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  return (count == 0);
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  return (count == MAX_SIZE);
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// HOW TO CALL: provide the element to be added
void queue::add(el_t elem)
{
  if (isFull())
    throw new Overflow("Cannot add a new element, queue is full");

  //std::cout << "[" << front << ";" << count << ";" << rear << "] Adding : " << elem << std::endl;  
  ++this->count;
  this->el[this->rear] = elem;
  this->rear = incr(this->rear);
  //std::cout << "Result: [" << front << ";" << count << ";" << rear << "]" << std::endl;
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void queue::remove(el_t& elem)
{
  if (isEmpty()) {
    std::cerr << "Error: Stack is empty, exiting..." << std::endl;
    exit(-1);
  }

  frontElem(elem);
  //std::cout << "[" << front << ";" << count << ";" << rear << "]Removing : " << elem << std::endl;
  this->front = nextElem(this->front);
  --this->count;
  //std::cout << "Result: [" << front << ";" << count << ";" << rear << "]" << std::endl;
}

// PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // TO CALL: provide a holder for the element (pass by ref)
void queue::frontElem(el_t& elem)
{
  elem = this->el[this->front];
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return this->count;
}

// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
  if (this->getSize() == 0)
    std::cout << "[ empty ]" << std::endl;
  else
    for (int i = this->front; (i + 1) != this->rear; i = incr(i))
      std::cout << "[ " << this->el[i] << " ]" << std::endl;
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
void queue::goToBack()
{
  if (isEmpty())
    throw new Underflow("Cannot move to next element, queue is empty.");

  if (getSize() > 1) {
    this->rear = incr(this->rear);
    if (!isFull())
      this->el[this->rear] = this->el[this->front];
    this->front = incr(this->front);
  }
}
