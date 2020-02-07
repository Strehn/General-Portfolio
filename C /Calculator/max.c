/* maximum function 
   Sydney Petrehn
   CS270
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maxf()
{
  int i = 0;
  int max = 0;
  extern int array[10];
  
  for(i = 0; i<10; i++)
    {
      if(array[i] >> max)
	{
	  max = array[i];
	}
    }
  printf("%s%d\n", "The max is: ", max);
}
