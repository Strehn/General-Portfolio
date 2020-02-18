/*********************************************                                                                                                              
 * Id: petr8004                                                                                            
 *                                                                                                              
 * Wo8: Brute Force Pattern Matching Algorithm                                                        
                                                                                                       
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Function Prototypes
void search(char* pattern, char *text); 

//Function that reads from the command line                                                                      
int main(int argc, char *argv[]){
   // ----- VARIABLES -----
   int size = strlen(argv[1]);
   char pattern[size];
   strcpy(pattern, argv[1]);
   size = strlen(argv[2]);
   char text[size];
   strcpy(text, argv[2]);

   // ----- Call brute force algorithm -----
   search(pattern, text);                                                    
   return 0;
}

//Function that implements brute force search                                                                   
void search(char* pattern, char *txt){
   // ----- VARIABLES -----                                                                                      
   int length = strlen(pattern);
   int max = strlen(txt);
   int i,j;

   printf("Matches found at locations:");
   // ----- Compare pattern to text -----                                                                        
   for(i = 0; i <= max - length; i++)
   {
      for(j = 0; j < max; j++)
      {
         if(txt[i+j] != pattern[j])
	 {
	    break;
	 }
      }
      if(j == length)
      {
         printf(" %d", i);
      }
   }
   printf("\n");
}
