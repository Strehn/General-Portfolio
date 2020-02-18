/*********************************************                                                                               
 * Id: petr8004                                                                                                              
 *                                                                                                                    
 * Wo7: Extra Restrictred Tower of Hanoi Algorithm                                                                                 
 *********************************************/
#include <stdlib.h>
#include <stdio.h>

void TowerOfHanoi(int nDisks, char fromPeg, char withPeg, char toPeg);
void SwapA(int nDisks, char fromPeg, char withPeg, char toPeg);
//Function that reads from the command line                                                                                  
int main(int argc, char *argv[]){
   // ----- VARIABLES -----                                                                                                  
   int nDisks = atoi(argv[1]);
   // ----- Call Tower Function with base case -----                                                                         
   TowerOfHanoi(nDisks, 'A', 'B', 'C');
   return 0;
}

// function that computes the tower of hanoi puzzle, recursive                                                               
void TowerOfHanoi(int nDisks, char fromPeg, char withPeg, char toPeg){
   // ----- RECURSIVELY SOLVE TOWER OF HANOI -----
   if(nDisks == 1){                                                                                                          
      printf("MOVE %c TO %c\n", fromPeg, withPeg);     
      printf("MOVE %c TO %c\n", withPeg, toPeg);
      return;                                                                                                                
   } 

   TowerOfHanoi(nDisks - 1, fromPeg, withPeg, toPeg);
   printf("MOVE %c TO %c\n", fromPeg, withPeg);

   SwapA(nDisks - 1, toPeg, withPeg, fromPeg);
   printf("MOVE %c TO %c\n", withPeg, toPeg);

   TowerOfHanoi(nDisks - 1, fromPeg, withPeg, toPeg);
}

// function used to swap disks so they can be moved
void SwapA(int nDisks, char toPeg, char withPeg, char fromPeg){   
   if(nDisks == 1){
      printf("MOVE %c TO %c\n", toPeg, fromPeg);
      return;
   }   
   TowerOfHanoi(nDisks - 1, toPeg, fromPeg, withPeg);
   printf("MOVE %c TO %c\n", toPeg, fromPeg);
   TowerOfHanoi(nDisks - 1, withPeg, toPeg, fromPeg);
   return;
}
