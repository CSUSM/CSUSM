// =========================================================
//HW1P1 queue
//Your name: Mathias LANG
//Complier:  g++
//File type: source file queue.cpp

//================================================================

#include "queue.h"
// constructor 
queue::queue()  {}

//destructor 
queue::~queue() {}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()   {}

// PURPOSE: returns true if queue is full, otherwise false
bool isFull()   {}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// HOW TO CALL: provide the element to be added
void add(el_t)  {}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void remove(el_t&){}

// PURPOSE: if empty, throws an exception Underflow
   // if not empty, give back the front element (but does not remove it)
   // TO CALL: provide a holder for the element (pass by ref)
void frontElem(el_t&){}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int getSize(){}

// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
void displayAll(){}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
void goToBack(){}
