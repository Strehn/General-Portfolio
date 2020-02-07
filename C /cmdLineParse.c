/* Sydney Petrehn
   CS 270 Assignment One
   Reading From Command Line and parsing it
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----- Function Prototypes -----
int makearg(char *s, char ***args);

int main()
{
  // ----- Variables -----
  char **args, str[256]; 
  int argc, i, j, row, column;

  // ----- Allocate memory for args -----
  args = malloc(256 * sizeof(char*)); //rows
  for( i = 0; i < 256; i++)
    {
      args[i] = malloc(256 * sizeof(char)); //columns
    }
  
  // ----- Get the line of code -----
  printf("Enter a line of code "); 
  fgets(str, 256, stdin);

  // ----- Call the make arg program -----
  argc = makearg(str, &args); 

  // output the number of arguments found, and print the arguments. 
  printf("There are %d words. Here they are:\n", argc);

  if(argc == -1)
    {
      printf("Error reading line");
    }

  for(row = 0; row < argc +1; row++)
    {
      for(column = 0; column < 250; column++)
	{
	  if(args[row][column] != '\0')
	    {
	      printf("%c", args[row][column]);
	    }
	}
      printf("\n");
    }

  // ----- FREE MEMORY -----
  for( i = 0; i < 256; i++)
    {
      free(args[i]);
    }

  return 0;
}// end of main

/*
  Function to parse a string then return it to main
*/
int makearg(char *s, char ***args)
{
  // ----- VARIABLES -----
  int amount = 0;
  int loop = 1;
  int length = strlen(s);

  // info stored in s which is just a single array
  // needs to be seperated and put into args
  int j = 0;
  if(s[j] == '\0')
    {
      return -1;
    }// return -1 if an error occurs

  for(j = 0; j < length; j++)
    {
      // step through s 
      while(s[j] == ' ')
        {
          j++;
        }
      while(s[j] != ' ' && s[j] != '\0')
	{
	  args[0][amount][j] = s[j];
	  j++;
	  if(s[j] == ' ')
	    {
	      amount++;
	    }
	}
      if(s[j] == '\0')
        {
          exit;
        }
    }
  amount++;
  return amount++;
}
