/*********************************************                                                     
 * Id: petr8004                                                                                      
 *                                                                                                
 * Wo5: Tower of Hanoi Algorithm                                                                        
 *********************************************/
#include <stdlib.h>
#include <stdio.h>

void TowerOfHanoi(int nDisks, char fromPeg, char toPeg, char withPeg);

//Function that reads from the command line                                                           
 int main(int argc, char *argv[]){
   // ----- VARIABLES -----                                                                             
   int nDisks = atoi(argv[1]);
   // ----- Call Tower Function with base case -----                      
   TowerOfHanoi(nDisks, 'A', 'C', 'B');
   return 0;
}

// function that computes the tower of hanoi puzzle, recursive
void TowerOfHanoi(int nDisks, char fromPeg, char toPeg, char withPeg){
   if(nDisks == 1){
      printf("MOVE %c TO %c\n", fromPeg, toPeg);
      return;
   }
   TowerOfHanoi(nDisks - 1, fromPeg, withPeg, toPeg);
   printf("MOVE %c TO %c\n", fromPeg, toPeg);
   TowerOfHanoi(nDisks -1, withPeg, toPeg, fromPeg);
}
