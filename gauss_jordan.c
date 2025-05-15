/* ######### gauss_jordan.c #########
Author: eurus
Date: May 06, 2025
Description: C implementation of the Gauss Jordan Algorithm 
For Solve a system of equations AX =b.

*/


// Header
#include <stdio.h>


// Prototypes
void print_Matrix(double *matrix, int numRows, int numCols);
void augment_Matrices(double *augMatrix, double *A, int numRows, double *b, int numCols, int b_cols);
void un_augment_Matrix(double *augMatrix, int numRows, int numCols, double *b, int b_cols);


// Main function
int main(int argc, char *argv[]){


//Create matrices
double A[9] = {4,5,3,7,9,5,5,6,7};
double b[9] = {1,0,0,0,1,0,0,0,1};
double Aug[18];
double un_Aug[9];


//Augment matrix
augment_Matrices(Aug, A, 3, b, 6, 3);

// print matrices
printf("Matrix A \n");
print_Matrix(A, 3, 3);
printf("\n \n");

printf("Matrix b \n");
print_Matrix(b, 3, 3);
printf("\n \n");

printf("Matrix Aug \n");
print_Matrix(Aug, 3, 6);
printf("\n \n");


//un-augment matrix
un_augment_Matrix(Aug, 3, 6, un_Aug, 3);

// print matrices
printf("Matrix un_Aug \n");
print_Matrix(un_Aug, 3, 3);
printf("\n \n");


return 0;
}


// Subroutines

// Function to print a matrix to stdout
void print_Matrix(double *matrix, int numRows, int numCols){

    for (int i = 0; i < numRows; i++){
        for (int j = 0; j< numCols; j++){
            printf("%.2lf\t", matrix[i*numCols + j]);
            }
        printf("\n");
        }
}


//Function to augmented a matrix A with a matrix b to form  [A|b]
void augment_Matrices(double *augMatrix, double *A, int numRows, double *b, int numCols, int b_cols){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j ++){
            if (j >= (numCols-b_cols)){
                *(augMatrix+(i*numCols) + j) = *(b+(i*b_cols + ((numCols-j) -1) ));
                continue;
                // BUG - Currently function append b to A from Right to left 
                // (this does not affect answer though as answer is also read right to left)
                // However appearance of augment when printing is back to front.
                // NOTE - When fixing, fix un_augmenting function as well
                
            }
            *(augMatrix+(i*numCols) + j) = *(A+(i*numRows + j)); 
            // BUG - Function currently only works with square matrices. Fix to work for all matrices
        }
    }
}


//Function to extract solution the right hand side b from an augmented matrix [A|b]
void un_augment_Matrix(double *augMatrix, int numRows, int numCols, double *unAugMatrix, int b_cols){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            if (j >= (numCols-b_cols)){
                *(unAugMatrix+(i*b_cols + ((numCols-j) -1) )) = *(augMatrix+(i*numCols) + j);
            }   
        }
    }
}

// TODO - Function to do RREF 
// TODO - Function to implement Gauss-Jordan Alg