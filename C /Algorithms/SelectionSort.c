/*******************************************                                                                       
 * Id: petr8004                                                                                                             
 *                                                                                                                           
 * Wo9: Selection Sort Algorithm                                                                             
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Function Prototypes                                                                                                       
void SS(int arr[], int n);
void swap(int *xp, int *yp);
void printA(int arr[], int size);

//Function that reads from the command line                                                                                  
int main(int argc, char *argv[]){
   // ----- VARIABLES -----                                                                                                  
   // array of integers
   int text[argc - 1];
   int i = 0;
   for( i = 0; i < argc - 1; i++)
   {
      text[i] = atoi(argv[i+1]);
   }
   
   // ----- Call selection sort algorithm -----                                                                            
   SS(text, argc);
   return 0;
}

// Function to swap two values in an array
void swap(int *xp, int *yp){
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

//Function that implements brute force search                                                                               
void SS(int arr[], int n){
   // ----- VARIABLES -----                                                                                                  
   int i,j, min;

   // ----- print the array -----                                                                                          
   printA(arr,n);

   // ----- Sort the Array -----                                                                                     
   for(i = 0; i < n-2; i++)
   {
      //----- find the minimum element -----
      min = i;
      for(j = i+1; j < n-1; j++)
      {
         if( arr[j] < arr[min])
         {
            min = j;
	 }
      }
      // ----- swap the elements -----                                                                                  
      swap(&arr[min], &arr[i]);
      // ----- print the array -----                                                                                    
      printA(arr,n);
   }
}

// Function to print the array
void printA(int arr[], int size){
   // ----- VARIABLES -----      
   int i;
   for(i = 0; i < size -1; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
   
}
