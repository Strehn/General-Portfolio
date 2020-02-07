/* Sum Function
   Sydney Petrehn
   CS 270
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sumf()
{
  int suma = 0;
  int temp = 0;
  int i = 0;
  extern int array[10];
  
  for(i = 0; i < 10; i++)
    {
      temp = suma + array[i];
      suma = temp;
    }
  
  printf("%s%d\n", "The sum of all numbers is: ", suma);

}
