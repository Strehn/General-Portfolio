/* 
   customer.h

   class for a linked list of integers and names;

 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string.h>
#include <iostream>
#include "customer.cpp"

using namespace std;

class Customer{
 private:
  struct node
  {
    int items;
    string name;
    node * next;
  };

  typedef node * nodeptr;

  nodeptr head;

 public:
  void AddNodeC(int x, string n);
  void DeleteC();
  int lengthC();
  string getnameC();
  int getitemsC();
  bool IsEmptyC();
};

#endif /* CUSTOMER_H */
