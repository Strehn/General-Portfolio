/*********************************************                              
 * Id: petr8004                                                                            
 *                                                                                             
 * Wo4: Program to calculate matrix from command line                                            
 * Input: Array of A[0,,n-1]) of integers given as command line arguements                           
 * Output: Array of floats of resolved system   
 *********************************************/
#include <stdlib.h>
#include <stdio.h>

void printMatrix(int rows, int columns, float **A);
void GE(int rows, int columns, float **A);

//Function that reads from the command line                                                       
int main(int argc, char *argv[]){// input is a n X (n+1) matrix
   // ----- VARIABLES -----                                                                         
   int  n, place, i, j, rows, columns;
   place = 1;
   // ----- get the number of systems -----
   n = atoi(argv[1]);                                                                     
   float **A = (float **)malloc(n * sizeof(float *));

   for( i = 0; i < n; i++){
      A[i] = (float *)malloc((n+1) * sizeof(float *));
   }

   rows = n; 
   columns = n + 1;

   //----- put argv into A -----                                                                         
   for( i = 0; i < rows; i++){
      for( j = 0; j < columns; j++){
         A[i][j] = atoi(argv[place+1]);
         place++;
      }
   }

   // ----- Gaussian Elemination on Matrix ----
   GE(n, n+1, A);
   return 0;
}

// function prints out the values of the matrixes given
void GE(int rows, int columns, float **A){
   // ----- VARIABLES -----
   int i, j, k;
   float tempji;
   printMatrix(rows, columns, A);
   printf("\n");

   // ----- n x (n+1) matrix ----- 
   for(i = 0; i <= rows-2; i++){
      for(j = i +1; j <= rows - 1; j++){
         tempji = A[j][i]; 
         for(k = i; k <= rows; k++){
            A[j][k] = A[j][k] - (A[i][k] * tempji) / A[i][i];
	 }
      }
      printMatrix(rows, columns, A);
      printf("\n");
   }
   
}

// function to print matrix
void printMatrix(int rows, int columns, float **A){
   // ----- Variables -----
   int i, j;
   for(i = 0; i < rows; i++){                                                                             
      for(j = 0; j < columns; j++){                                                                       
         printf("%.2f ", A[i][j]);                                                                        
         
      }
      printf("\n");
   }     
}
