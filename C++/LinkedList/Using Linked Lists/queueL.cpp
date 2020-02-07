/*  queueL.cpp
 *
 *  Definition file for the ADT queue.
 *  Implementation uses a list.
 */
#include <iostream>
#include "QueueL.h"
#include "customer.h"

void Queue::Insert(string name, int items)
{
  L.AddNodeC(items, name);
}

void Queue::Delete()
{
  L.DeleteC();
}

bool Queue::IsEmpty()
{
  L.IsEmptyC();
}

int Queue::length()
{
  L.lengthC();
}

string Queue::getname()
{
  L.getnameC();
}

int Queue::getitems()
{
  L.getitemsC();
}


