/* Main Function and Global Array 
   Sydney Petrehn
   CS 270
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sum.c"
#include "average.c"
#include "min.c"
#include "max.c"

//----- GLOBAL ARRAY -----
int array[10];

void main(void)
{
  //----- VARIABLES -----
  int random;
  int i = 0;

  //----- FILL THE ARRAY -----
  for(i = 0; i < 10; i++)
    {
      random = (rand() % 100 +1);
      array[i] = random;
    }

  //----- CALL THE FUNCTIONS -----
  sumf();
  averagef();
  minf();
  maxf();
}
