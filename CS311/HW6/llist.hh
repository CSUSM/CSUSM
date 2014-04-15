// ====================================================
// HW3P1 llist
// Your name: Mathias LANG
// Compiler:  g++
// File type: Linked list header file
//=====================================================

typedef int el_t ;

// list node is defined here as a struct Node
struct Node
{
  el_t	Elem;   // elem is the element stored
  Node	*Next;  // next is the pointer to the next node
};

// I could have done class Node and add the data members under public
// but it will use too much space


class llist {  
protected:
  Node *Front;       // front  pointer 
  Node *Rear;        // rear   pointer
  int  Count;        // counter for the number of elements
  
public:
  class Underflow {};
  class OutOfRange {};
    
  llist ();                       // constructor  
  ~llist();                       // destructor
  
  /// PURPOSE: Check if the list is empty.
  bool isEmpty() const;
  /// PURPOSE: Pretty-print all the elements on the screen.
  void displayAll() const;

  /// HOW TO CALL: The NewNum parameter is the element to add.
  /// PURPOSE: Add an element at the beginning of the list.
  void addFront(el_t NewNum);
  /// HOW TO CALL: The NewNum parameter is the element to add.
  /// PURPOSE: Add an element at the end of the list.
  void addRear(el_t NewNum);
  /// HOW TO CALL:  The 'I' parameter is the index where to add;
  ///				The NewNum parameter is the element to add.
  /// PURPOSE: Add an element at a specific position in the list.
  void addbeforeIth(int I, el_t newNum);

  /// HOW TO CALL: The removed element will be set in OldNum.
  /// PURPOSE: Remove the first element of the list.
  void deleteFront(el_t& OldNum);
  /// HOW TO CALL: The removed element will be set in OldNum.
  /// PURPOSE: Remove the last element of the list.
  void deleteRear(el_t& OldNum);
  /// HOW TO CALL:  The 'I' parameter is the index where to delete;
  ///				The removed element will be set in OldNum.
  /// PURPOSE: Remove an element at a specific position in the list.
  void deleteIth(int I, el_t& OldNum);
};
