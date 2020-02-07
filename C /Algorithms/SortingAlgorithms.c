/* 
   Sydney Petrehn
   CS 270
   Sorting Function
   September 10, 2018
*/

#include <stdio.h>

// ----- GLOBAL VARIABLES -----

// ----- FUNCTION PROTOTYPES -----
void swap(char *x, char *y);
void bubbleSort(char ***args);
void insertSort(char ***args);
void quicksort(char ***args);
void getData(char *data);
void makearg(char*s, char ***args);


int main()
{
  // ----- VARIABLES -----
  char inputarr[262144];
  char **table;
  int max_line = 256;
  int max_string = 262144;

  // ----- ALLOCATE MEMORY -----
  table = malloc(max_line * sizeof(char*)); // rows

  for(i = 0; i < max_string; i++)
    {
      table[i] = malloc(max_line * sizeof(char)); // columns
    }

  // ----- GET INPUT -----
  printf("Getting input from 'hw2data.txt'");
  
  getData(inputarr);
  makearg(inputarr, table);

  // ----- BUBBLE SORT -----
  bubbleSort(table);
  
  // ----- INSERT SORT -----
  // redo input
  printf("Getting input from 'hw2data.txt'");

  getData(inputarr);
  makearg(inputarr, table);

  insertSort(table);

  // ----- QUICK SORT -----
  // redo input
  printf("Getting input from 'hw2data.txt'");

  getData(inputarr);
  makearg(inputarr, table);

  quickSort(table);

  // ----- DEALLOCATE MEMORY -----
  for( i = 0; i < max_string; i++)
    {
      free(table[i]);
    }
  free(table);
  
  return 0;
} // end of main

// ----- FUNCTIONS -----

// READ INPUT FUNCTION
void getData(char *data)
{
  // ----- VARIABLES -----
  int max_line = 262144; // amount of characters in whole program will parse later
 
  // file name: hw2data.txt
  // open the file
  fgets(data, max_line, stdin);
  // close the file
}

// SWAP FUNCTION
void swap(char *x, char *y)
{
  // ----- VARIABLES -----
  char temp;
  int i;

  // ----- SWAP ALGORITHM -----
  for(i = 0; i < 256; i++) // completly switches each row in the table 
    {
      temp = x[i];
      x[i] = y[i];
      y[i] = x[i];
    }
}

// MAKE TABLE FUNCTION
int makearg(char *s, char ***args) // makes a string table to send back to main
{
  // ----- VARIABLES -----
  int value = 0;
  int length = strlen(s);
  int j, i = 0;

  for (j = 0; j < length; j++)
    {

      // save up to the space into args
      args[0][value][i] =  s[j];
      i++;
      // checks to see if the next one is a space
      if (s[j + 1] == ' ')
	{
	  args[0][value][j + 1] = '\0';
	  value++;
	  i = 0;
	  j++;
	}
      if (s[j + 1] == '\0') // checks to see if the end of a program
	  {
	    args[0][value][j + 1] = '\0';

	  }

    }
  return value++; // gives how many rows there are which is also how many w ords there are

    }

// BUBBLE SORT FUNCTION
void bubbleSort(char ***args);
{
  // ----- VARIABLES -----
  int i,k,l;
  int j = 0;
  int maxs = 256;
  int maxr = 261244;
  char tempa[256];
  char tempb[256];

  // ----- SORTING ALGORITHM -----
  for( i = 0; i < maxr; i++) 
    {
      if(args[0][i][j] > args[0][i+1][j]) // checks the first letter of the strings
	  {
	    for(k = 0; k < 256; k++)
	      {
		tempa[k] = args[0][i][k];
		tempb[k] = args[0][i+1][k];
	      }
	    swap(temp[a], temp[b]);
	    for(k = 0; k < 256; k++)
	      {
		args[0][i][k] = tempa[k];
		args[0][i+1][k] = tempb[k];
	      }
	    else if(args[0][i][j] == args[0][i+1][j]) // in case the first letters are the same
	      {
		if( args[0][i][j+1] > args[0][i+1][j+1])
		  {
		    for(k = 0; k < 256;k++)
		      { 
			tempa[k] = args[0][i][k];
			tempb[k] = args[0][i+1][k];
		      }
		    swap(temp[a], temp[b]);
		    for(k = 0; k < 256;k++)
		      { 
			args[0][i][k] =tempa[k];
			args[0][i+1][k]= tempb[k];
		      }
		  }
	      }
	  }
     }
}


// INSERTION SORT FUNCTION
void insertSort(char ***args);
{
  // ----- VARIABLES -----
  int i,k,l;
  int j = 0;
  int maxs = 256;
  int maxr = 261244;
  char tempa[256];
  char tempb[256];

  // ----- SORTING ALGORITHM -----


}


// QUICK SORT FUNCTION
void quicksort(char ***args)
{
  // ----- VARIABLES -----
  int i,k,l;
  int j = 0;
  int maxs = 256;
  int maxr = 261244;
  char tempa[256];
  char tempb[256];

  // ----- SORTING ALGORITHM -----

}
