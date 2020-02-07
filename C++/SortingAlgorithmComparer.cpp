/* Sydney Petrehn

   Prog6.cpp
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// ----- Function prototypes -----
void fillrandom(int *a, int size);
void filllow(int*a, int size);
void fillhigh(int *a, int size);
void swap(int *x, int *y);
void selectsort(int *a, int size);
void  quicksort(int *a, int first, int last);
void mergesort(int*a, int first, int last);
int Pivot( int  *a, int first, int last );
void Merge( int a[], int firstLeft,  int lastLeft, int firstRight, int lastRight );

int main()
{
  //----- Data Storage -----
  // im just going to make arrays of values
  int small = 100;
  int medium = 1000;
  int large = 10000;

  int random[100];
  int randomm[1000];
  int randoml[10000];

  int low[100];
  int lowm[1000];
  int lowl[10000];

  int high[100];
  int highm[1000];
  int highl[10000];

  // ----- Calling functions to add things into the arrays -----
  fillrandom(random, small);
  fillrandom(randomm, medium);
  fillrandom(randoml, large);

  filllow(low, small);
  filllow(lowm, medium);
  filllow(lowl, large);
  
  fillhigh(high, small);
  fillhigh(highm, medium);
  fillhigh(highl, large);
  // all arrays are filled and sorted now using Selection, Quicksort, And Mergesort
  // selection sort
  selectsort(random, small);
  selectsort(randomm, medium);
  selectsort(randoml, large);
  selectsort(low, small);
  selectsort(lowm, medium);
  selectsort(lowl, large);
  selectsort(high, small);
  selectsort(highm, medium);
  selectsort(highl, large);

  // ----- RESET EVERYTHING AFTER SELECT SORT -----
  fillrandom(random, small);
  fillrandom(randomm, medium);
  fillrandom(randoml, large);

  filllow(low, small);
  filllow(lowm, medium);
  filllow(lowl, large);

  fillhigh(high, small);
  fillhigh(highm, medium);
  fillhigh(highl, large);
  // all arrays refilled and reset
  //Quicksort
  int first = 0;
  quicksort(random, first, small -1);
  quicksort(randomm, first, medium -1);
  quicksort(randoml, first,  large -1);
  quicksort(low,first, small-1);
  quicksort(lowm,first, medium-1);
  quicksort(lowl,first, large -1);
  quicksort(high,first, small-1);
  quicksort(highm,first, medium-1);
  quicksort(highl,first, large-1);
  
  // ----- RESET EVERYTHING AFTER QUICKSORT -----
  fillrandom(random, small);
  fillrandom(randomm, medium);
  fillrandom(randoml, large);

  filllow(low, small);
  filllow(lowm, medium);
  filllow(lowl, large);

  fillhigh(high, small);
  fillhigh(highm, medium);
  fillhigh(highl, large);
  // all arrays refilled and reset
  //Mergesort
  mergesort(random,first, small -1);
  mergesort(randomm,first, medium-1);
  mergesort(randoml,first, large-1);
  mergesort(low,first, small-1);
  mergesort(lowm,first, medium-1);
  mergesort(lowl,first, large-1);	
  mergesort(high,first, small-1);
  mergesort(highm,first, medium-1);
  mergesort(highl,first, large-1);

  return 0;
}
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
void fillrandom(int *a, int size)
{
  int randomvalue;
  for(int i = 0; i < size; i++)
    {
      randomvalue = rand() % 101;
      a[i] = randomvalue;
    }
}
void filllow(int*a, int size)
{
  // fill it first with just random values
  int randomvalue;
  for(int i = 0; i < size; i++)
    {
      randomvalue = rand() % 101;
      a[i] = randomvalue;
    }
  // sort it low to high using bubble sort method
  int i, j;
  for(i=0; i < size; i++)
    {
      for(j=0; j < size; j++)
	{
	  if(a[j] > a[j+1])
	    {
	      int temp = a[j];
	      a[j] = a[j + 1];
	      a[j+1] = temp;
	    }
	}
    }
}
void fillhigh(int *a, int size)
{
  // fill it first with just random values
  int randomvalue;
  for(int i = 0; i < size; i++)
    {
      randomvalue = rand() % 101;
      a[i] = randomvalue;
    }
  // sort high to low using bubble sort method
  int i, j;
  for(i=0; i < size; i++)
    {
      for(j=0; j < size; j++)
	{
          if(a[j] < a[j+1])
            {
	      int temp = a[j];
              a[j] = a[j + 1];
	      a[j+1] = temp;
            }
        }
    }

}
void selectsort(int *a, int size)
{
  int i, j, minindex;
  int tempx, tempy;
  int count;
  for(i = 0; i< size; i++)
    {
      minindex = i;
      for(j = i+1; j < size; j++)
	{
	  if(a[j] < a[minindex])
	    {
	      minindex = j;
	    }
	}
      count ++;
      tempx = a[minindex];
      a[minindex] = a[i];			
      a[i] = tempx;
    }
  cout<< "select sort took" << count << " iterations." << endl;
}
void quicksort(int *a, int first, int last)
{
  int pivot;
  int count;
  if( first < last ) {
    pivot = Pivot( a, first, last );
    quicksort( a, first, pivot-1 );
    quicksort( a, pivot+1, last );
    count ++;
  }
  
}
void mergesort(int*a, int first, int last)
{
  int  middle;

  if( first < last ) {
    middle = (first + last)/2;
    mergesort( a, first, middle);
    mergesort( a, middle+1, last );
    Merge( a, first, middle, middle+1, last );
  }
}

int Pivot( int *a, int first, int last ) 
{
  int  p = first;
  int pivot = a[first];
  int count;
  for( int i = first+1 ; i <= last ; i++ ) {
    if( a[i] <= pivot ) {
      p++;
      swap( a[i], a[p] );
      count++;
    }
  }

  swap( a[p], a[first] );
  if(count > 1010000570)
    {
      cout<< "quick sort took" << count <<" iterations." << endl;
    }
  return p;
}
void Merge( int a[], 
            int firstLeft,  int lastLeft, 
            int firstRight, int lastRight ) 
{
  int tempArray[10000];
  int  index = firstLeft;
  int  firstSave = firstLeft;
  int count;
  //  Merge segments (array subsets)
  while( (firstLeft <= lastLeft) && (firstRight <= lastRight) )
    {
      if( a[firstLeft] < a[firstRight] )
        {
	  tempArray[index] = a[firstLeft];
	  firstLeft++;
        }
      else
        {
	  tempArray[index] = a[firstRight];
	  firstRight++;
        }
      index++;
      count++;
    }
  //  Copy remainder of left array into tempArray
  while( firstLeft <= lastLeft )
    {
      tempArray[index] = a[firstLeft];
      firstLeft++;
      index++;
      count++;
    }

  //  Copy remainder of right array into tempArray
  while( firstRight <= lastRight )
    {
      tempArray[index] = a[firstRight];
      firstRight++;
      index++;
      count++;
    }

  //  Copy back into original array
  for( index = firstSave ; index <= lastRight ; index++ )
    {
    a[index] = tempArray[index];
    count++;
    }
  if(count > 5050)
  cout<< "Merge Sort Took:" << count << " Iterations" << endl;
}
