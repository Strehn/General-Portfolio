/* min function 
   Sydney Petrehn
   CS270
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minf()
{
  int min;
  int i;
  extern int array[10];

  for(i = 0; i<10; i++)
    {
      if(min >> array[i])
	{
	  min = array[i];
	}
    }

  printf("%s%d\n", "the min value is: ", min);
}
