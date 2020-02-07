/*********************************************
 * Id: petr8004
 * 
 * Wo1: Program to find minimum distance between two elements of an array 
 *********************************************/ 
#include <stdlib.h>
#include <stdio.h>   
   
int MinDistance(int  argc, int arg[]);

//Function that reads from the command line 
int main(int argc, char *argv[]){
   // ----- VARIABLES -----
   int arg[argc], dmin;
   int i, j = 1;
   for(i=0; j < argc; i++){
      arg[i]=atoi(argv[j]);
      j++;
   }
   // ----- FIND THE MIN DISTANCE -----
   dmin = MinDistance(argc, arg); 
   printf("%d\n", dmin);
   return 0;
   }
   
// function returns the minimum distance between two elements of an array
int MinDistance(int  argc, int arg[]){
   // ----- VARIABLES -----
   int min = 100, i, j;

   // ----- Finding the minimum -----
   for(i=0; i < argc-1; i++){
      for(j=0; j < argc-1; j++){
         if( (i != j) && ( abs(arg[i] - arg[j]) < min) ){
            min = abs(arg[i]-arg[j]);
         }
      }
   }
   return min;
   }

