//Sydney Petrehn
// Cryptography
// Hill Cipher Encrypt and Decrypt

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

# define MAX_SIZE 200

struct MATRIX{
    int arr[MAX_SIZE][MAX_SIZE];
};

void enc_Hill(char message[], char key[], int ksize, int msize);
void dec_Hill(char cipher[], char key[], int ksize, int msize);
void createIntMatrix(struct MATRIX *temp, char keystring[], int matrixsize);
int createIntVector(struct MATRIX *t, char text[], int ksize, int msize);
void matrixMultiply(struct MATRIX *kMatrix, struct MATRIX *mVector, int ksize, int msize);
void printArray(char array[], int size);
void Cofactor(struct MATRIX *kMatrix, struct MATRIX *tMatrix, int row, int column, int n);
int determinant(struct MATRIX *kMatrix, int n);
void adjoint(struct MATRIX *kMatrix, struct MATRIX *adjMatrix, int n);
void inverse(struct MATRIX *kMatrix, struct MATRIX *IMatrix, int n);

int main(int argc, char *argv[]){
    // input = ./file.out message key matrixsize
    int temp = 0, ksize = 0, msize = 0;
    sscanf(argv[3], "%d", &ksize); // key matrix size 
    msize = strlen(argv[1]); // message size
    char argm[msize];  // store the message string
    char argk[ksize]; // store the key string
    strcpy(argm, argv[1]);
    strcpy(argk, argv[2]); 

    printf("%s", "Encrypt: press 1 \n Decrypt: press 2 \n");
    scanf("%d", &temp);
    switch(temp){
        case 1: 
            printf("%s%s\n", "String to Encrypt: ", argm);
            printf("%s%d\n", "Message Size: ", msize);
            printf("%s%s\n", "Key String: ", argk);
            printf("%s%d\n", "Key Matrix Size: ", ksize);
            enc_Hill(argm, argk, ksize, msize); 
            break;
        case 2: 
            printf("%s%s\n", "String to Decrypt: ", argm);
            printf("%s%d\n", "Message Size: ", msize);
            printf("%s%s\n", "Key String: ", argk);
            printf("%s%d\n", "Key Matrix Size: ", ksize);
            dec_Hill(argm, argk, ksize, msize); 
            break;
    }
    return 0;
}

void enc_Hill(char message[], char key[], int ksize, int msize){
    int q = 0; 
    struct MATRIX kMatrix; 
    createIntMatrix(&kMatrix, key, ksize);
    struct MATRIX mVector; 
    q = createIntVector(&mVector, message, ksize, msize);
    msize += q;
    matrixMultiply(&kMatrix, &mVector, ksize, msize);
}

void dec_Hill(char cipher[], char key[], int ksize, int msize){
    int q = 0;
    struct MATRIX kMatrix; 
    createIntMatrix(&kMatrix, key, ksize);
    struct MATRIX IMatrix;
    // calculate inverse by adj(x)/det(x)
    inverse(&kMatrix, &IMatrix, ksize);
    struct MATRIX cVector; 
    q = createIntVector(&cVector, cipher, ksize, msize);
    msize += q;
    matrixMultiply(&kMatrix, &cVector, ksize, msize);
 }

void createIntMatrix(struct MATRIX *temp, char keystring[], int matrixsize){
    int i = 0, j = 0, k = 0, z = 0;
    for(i = 0; i < matrixsize; i++){
        for(j = 0; j < matrixsize; j++){
            z = keystring[k] - '0'; 
            temp->arr[i][j] = z;
            k++;
        }
    }
}

int createIntVector(struct MATRIX *t, char text[], int ksize, int msize){
    int i = 0, j = 0, k = 0, x = 0, y = 0, q = 0, temp = 0;
    q = msize % ksize; // if not even add q's to end of message 
    if(q == 0){
       y = msize / ksize; // number of columns
    }
    else{
        y = msize + q; // get a mod remainder of 0
        y = y / ksize; // number of columns
    }
    for(i = 0; i < ksize; i++){ // for an nxn matrix we need vertical groups of n letters
        for(j = 0; j < y; j++)  {
            temp = text[j] - '0'; // integer value of character 
            temp = temp - 97; // ASCII difference from letters to decimal numbers 0-26
            t->arr[i][j] = temp;
        }
    }
    if(q != 0){
        for(x = 0; x < q; x++){
            t->arr[i][j] = 113 - 97; // 113 is value of q
            j++;
        }
    }
    return q;
}

void matrixMultiply(struct MATRIX *kMatrix, struct MATRIX *mVector, int ksize, int msize){
    /* Matrix * Vector   
       a b c   x     ax + by + cz
       d e f * y =   dx + by + cz
       g h i   z     gx + hy + iz
    */
    char text[msize];
    int i = 0, j = 0, k = 0, x = 0, temp = 0;
    for(i = 0; i < ksize; i++){
        for(j = 0; j < ksize; j++){
            temp = temp + (kMatrix->arr[i][j] * mVector->arr[k][x]); // mod 26 to stay in alphabet
            k++;
        }
        k = 0; // reset vector row to 0
        temp = temp % 26; // stay in alphabet
        //temp = temp + 97; // move back to ASCII lowercase which is 97 - 122
        text[i] = (char) temp; // need to do this for C's memory stuff to convert int to char*
        x++; // increase vector column
        temp = 0; // clear temp
    }
    printArray(text, msize);
}

void printArray(char array[], int size){
    int i = 0; 
    for( i = 0; i < size; i++){
        printf("%c", array[i]);
    }
    printf("\n");
}

 void Cofactor(struct MATRIX *kMatrix, struct MATRIX *tMatrix, int row, int column, int n){
    // copy into the temp matrix values not in the given row or column
    int i = 0, j = 0, k = 0, x = 0; 
    for( x = 0; x < n; x++){
        for(k = 0; k < n; k++){
            if(x != row && k != column){
                tMatrix->arr[i][j+1] = kMatrix->arr[x][k];
                j++;
                if( j == n-1){
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(struct MATRIX *kMatrix, int n){
    // recursive function to get to the determinant of the Matrix. 
    int det = 0, i = 0;
    if(n == 1){
        return kMatrix->arr[0][0];
    }
    struct MATRIX tMatrix;
    int sign = 1; // if i+j %2 = 0 even otherwise odd. 
    for(i = 0; i < n; i++){
        Cofactor(kMatrix, &tMatrix, 0, i, n);
        det += sign * kMatrix->arr[0][i] * determinant(&tMatrix, n - 1);

        sign = -sign; // terms alternate signs for even and odd values. 
    }
    return det;
}

void adjoint(struct MATRIX *kMatrix, struct MATRIX *adjMatrix, int n){
    // get adjoint of kMatrix and store it in adjMatrix
    int i = 0, j = 0, sign = 1; 
    struct MATRIX tMatrix;
    if(n == 1){
        adjMatrix->arr[0][0] = 1;
        return;
    }
    for( i = 0; i < n; i++){
        for( j = 0; j < n; j++){
            Cofactor(kMatrix, &tMatrix, i, j, n); // cofactor matrix[i][j]
            if( ( (i + j) % 2) == 0){
                if(sign < 0){sign = sign * -1;} 
            } // sign is even if sum of row and column indexes is even
            else{ 
                if(sign > 0){sign = sign * -1;} 
            } //sign is odd if sum of row and column indexes is odd
            adjMatrix->arr[j][i] = (sign) * (determinant(&tMatrix, n - 1));
        }
    }
}

void inverse(struct MATRIX *kMatrix, struct MATRIX *IMatrix, int n){
    int i = 0, j = 0, det = 0;
    struct MATRIX adjMatrix;
    det = determinant(kMatrix, n);
    adjoint(kMatrix, &adjMatrix, n);
    //calculate inverse by adj(x)/det(x)
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            IMatrix->arr[i][j] = (adjMatrix.arr[i][j] / (int) det);
        }
    }
}
