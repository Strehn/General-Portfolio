/*  QueueL.h
 *
 *  Interface file for the ADT queue.
 *  Implementation uses a list.
 */

#ifndef QUEUE_L_H
#define QUEUE_L_H

#include "customer.h"
#include "customer.cpp"
#include "queueL.cpp"

class Queue
{
 private:
  Customer L;   //  list of queue items

 public:
  void Insert(string name, int items);
  void Delete();
  int  length();    
  bool IsEmpty();
  string getname();
  int getitems();
};
#endif
