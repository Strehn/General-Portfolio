/*********************************************
 * Id: petr8004
 * 
 * Wo3: Very inneficient program to compute 2^n 
 *********************************************/ 
#include <stdlib.h>
#include <stdio.h>   
   
int power(int i);

//Function that reads from the command line 
int main(int argc, char *argv[]){
   // ----- VARIABLES -----
   int j, compute;
   j = atoi(argv[1]);

   // ----- Call power function -----
   compute = power(j);
   printf("%d\n", compute);
   return 0;
}
   
// function returns the calculation 2^n
int power(int i){
   // ----- Variables -----
   int sum = 0;
   // ----- Recursively find 2^n -----
   if(i < 1){
      return 1;
   }
   else{
      sum += power(i-1) + power(i-1);
      return ( sum );
   }
}

