/* Average function 
   Sydney Petrehn
   CS270
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void averagef()
{
  int temp = 0;
  int avg = 0;
  int i = 0;
  extern int array[10];

  for(i = 0; i < 10; i++)
    {
      temp = avg + array[i];
      avg = temp;
    }

  avg = avg/10;
  
  printf("%s%d\n", "The average is: ", avg);
  

}
