// =========================================================
//HW1P1 stack
//Your name: Mathias LANG
//Compiler:  g++
//File type: Implementation (source) file

//================================================================

#include    <iostream>
#include    "stack.h"

//** Constructor don't need to do any work.
stack::stack()  {}

// ** Destructor does not have to do anything since this is a static array.
stack::~stack() {} // nothing to do
 
// ** isEmpty checks the vector and returns true if empty, false otherwise.
bool stack::isEmpty()   { return this->data.empty(); }

// ** isFull is always false.
bool stack::isFull()    { return (false); }

// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{
    if (isFull())
        throw Overflow();
    else
        data.push_back(elem);
}

// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else {
        elem = data.back();
        data.pop_back();
    }
}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
{
    if (isEmpty())
        throw Underflow();
    else
        elem = data.back();
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{
    if (isEmpty())
        std::cout << "[ empty ]" << std::endl;
    else
        for (std::vector<int>::reverse_iterator it = data.rbegin();
             it != data.rend(); ++it)
            std::cout << *it << std::endl;
}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void    stack::clearIt()
{
    int tmp;
    while (!isEmpty())
        pop(tmp);
}
