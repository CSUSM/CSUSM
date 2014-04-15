// -*- C++ -*-
#ifndef SLIST_HH__
#define SLIST_HH__

#include "llist.hh"

class slist : public llist {
public:
  // Default constructor.
  slist();
  // PURPOSE :	Find an item in the list.
  // RETURNS :	The index of this item + 1, or 0.
  int search(el_t Key);
  // PURPOSE :	go to the Ith node (I is between 1 and Count)
  //			and replace the element there with Elem. 
  //		If I was an illegal value, throw an exception.
  // PARAMS :	- Elem is the el_t to place in the list. 
  //	        - I is the (index + 1) at which we want to replace;
  void replace(el_t Elem, int I);

  // PURPOSE : Create a copy of o.
  // PARAMS : 'o' : Any slist.
  slist(const slist& o);


  // PURPOSE : Replace the content of the list with the content of 'o'.
  // PARAMS : 'o' Any slist.
  slist& operator=(const slist& o);

  // PURPOSE : Compare the values in this and 'o' and tell if they're equals.
  // PARAMS : 'o' is any slist.
  bool operator==(const slist& o);

};

#endif /* !SLIST_H__ */
