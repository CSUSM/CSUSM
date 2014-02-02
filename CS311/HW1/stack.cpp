// =========================================================
//HW1P1 stack
//Your name: Mathias LANG
//Compiler:  g++
//File type: Implementation (source) file

//================================================================

#include    <iostream>
#include    "stack.h"

//** Constructor must initialize top to be -1 to begin with.
stack::stack()  { top = -1; } // indicate an empty stack

// ** Destructor does not have to do anything since this is a static array.
stack::~stack() {} // nothing to do
 
// ** isEmpty checks top and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()   { return (top == -1); }

// ** isFull checks top and returns true if full, false otherwise.
// In the comment, make sure you define "full" in terms of top.
bool stack::isFull()    { return (top == MAX - 1); }
  
// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{
    if (isFull())
        throw Overflow();
    else
        el[++top] = elem;
}
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else
        elem = el[top--];
}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else
        elem = el[top];
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{
    if (isEmpty())
        std::cout << "[ empty ]" << std::endl;
    else
        for (int i = top; i >= 0; --i)
            std::cout << el[i] << std::endl;
}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void    stack::clearIt()
{
    int tmp;
    while (!isEmpty())
        pop(tmp);
}
