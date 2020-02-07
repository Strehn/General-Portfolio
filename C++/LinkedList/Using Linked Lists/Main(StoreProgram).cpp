/* sydney petrehn
   programming assignment #3
   making a store with 3 lines using queues
*/
#include <fstream>
#include <iostream>
#include "QueueL.h"
#include "customer.h"

using namespace std;

// ----- function prototypes -----
bool iterations(int i);
bool iterationsE(int t);

int main()
{
  // ----- Variables -----
  int time,items,iter,fill, temp, length1, length2, length3;
  string name;
  ifstream infile;
 
  // ----- file -----
  infile.open("shop2.dat");
  if(!infile)
    {
      cout << "Error opening file" << endl;
    }
  // ----- Create the 3 lines of the store -----
  Queue line1;
  Queue line2;
  Queue line3;
  
  // ----- begin putting things into the lines -----
  iter = 1; // starting on the first tick
  temp = 1;
  infile >> time; // checks the first person's time of when they enter the queue

  while(time == 1) // so just putting the first people in the lines 
    {
      if(temp == 1)
	{
	  // ----- Put the data from the file into the queues -----    
	      infile >> name;
	      infile >> items;
	      line1.Insert(name, items);
	      temp++;
	      infile >> time;
	}
      if(temp == 2)
	{                          
              infile >>name;
              infile >>items;
              line2.Insert(name, items);
	      temp ++;
	      infile >> time;
        }
      if(temp == 3)
        {
              infile >>name;
              infile >>items;
              line3.Insert(name, items);
	      temp = 1; // reset so it will cycle back to the first queue
	      infile >> time;
        }
    }
  
  int nexin = 2;
  time = 2;

  // begin check out process
  while(time < 40)
    {
       while(time == nexin)
	{
	      // ----- Put the data from the file into the queues -----                        
              infile >> name;
              infile >> items;
              line1.Insert(name, items);
              infile >> nexin; 
	}// end of while

      //----- checkout line 1 (express so processes every 2 ticks)
      if(iterationsE(time) == true)
	{
	  line1.DeleteQ();// the first person gets deleted
	}
      // ----- checkout line 2 and line 3 
      if(iterations(time) == true)
	{
	  line2.DeleteQ();// the person getting checked out gets deleted
	  line3.DeleteQ();
	}
      
      // ----- move people from back to the shortest line 
      length1 = line1.length();
      length2 = line2.length();
      length3 = line3.length();

      if( length1 == 0 && length2 == 0 && length3 == 0)
	{
	  time = 100;
	}
      else if(length1 == 1 && (length2 == 0 && length3 == 0))
	{
	  line1.DeleteQ();
	  time = 100;
	}
      else if(length2 == 1 && (length1 == 0 && length3 == 0))
	  {
	    line2.DeleteQ();
	    time = 100;
	  }
      else if(length3 ==1 &&(length1 == 0 && length2 == 0))
	    {
	      line3.DeleteQ();
	      time = 100;
	    }
      else if(length1 > length2 && length1 > length3)
	{
	  name = line1.getname();
	  items = line1.getitems();
	  line1.Delete();
	  line2.Insert(name, items);
	}
      else if(length2 > length1 && length2 > length3)
	{
	   name = line2.getname();
          items = line2.getitems();
          line2.Delete();
          line1.Insert(name, items);
	}
      else if(length3 > length1 && length3 > length2)
	{
	  name = line3.getname();
          items = line3.getitems();
          line3.Delete();
	  line1.Insert(name, items);
	} 
      infile >> nexin;
      time++;    
    }// end of while

  cout << "out of while" << endl;

  // One of the lines is an express lane
  // express lane processes at one transaction each 2 clock cycles
  // other lanes process at 4 clock cycles
  
} // end of main

bool iterationsE(int i){ // checks to see for express lane if a customer has been checked out
  switch(i)
    {
  case 2:
      return true;
      break;
  case 4:
      return true;
      break;
  case 6:
      return true;
      break;
  case 8:
      return true;
      break;
  case 10:
      return true;
      break;
 case 12:
     return true;
     break;
 case 14:
     return true;
     break;
 case 16:
     return true;
     break;
 default:
   return false;
    }
}

bool iterations(int i){ // for the other lanes which aren't express
  switch(i)
   {
    case 4:
	return true;
	break;
    case 8:
	return true;
	break;
    case 12:
	return true;
	break;
    case 16:
	return true;
	break;
   case 20:
        return true;
        break;
   case 24:
        return true;
        break;
   case 28:
        return true;
        break;
    default:
      return false;
    }
}
