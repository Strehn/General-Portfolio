/*  customer.cpp                                                                                                                                                                                                
 *                                                                                                                                                                                                                                          
 *  Class for a sorted linked list of integers.                                                                                                                                                                       
 */

#include <iostream>
#include "customer.h"

using namespace std;

void Customer::AddNodeC(int x, string na)
{
  nodeptr n = new node;
  nodeptr curr = new node;
  n-> items = x;
  n-> name = na;
  n -> next = NULL;
  if(head == NULL)
    {
      head = n;
    }
  else
    {
      curr = head;
      while( curr-> next != NULL)
	{
	  curr = curr -> next;
	}

      curr -> next = n;
    }
}                                                                                                                                                                                            
void Customer::DeleteC()
{
  if( IsEmptyC() == false)
  {
    nodeptr curr = new node;
    curr = head;
    head = curr -> next;
    cout << curr-> name << endl;
    delete curr;
    }
}

bool Customer::IsEmptyC()
{
  if(head ==NULL)
    {
      return true;
    }
  else
    return false;
}

int Customer::lengthC()
{
  int length;
  nodeptr p = new node;
  p = head;
  while(p!=NULL)
    {
      length++;
      p = p->next;
    }
  return length;
}

string Customer::getnameC()
{
  return head -> name;
}

int Customer::getitemsC()
{
  return head -> items;
}
