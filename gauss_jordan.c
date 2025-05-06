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

// Main function
int main(int argc, char *argv[]){
//Create matrices
double A[9] = {4,5,3,7,9,5,5,6,7};
double b[9] = {1,0,0,0,1,0,0,0,1};

// print matrices
printf("Matrix A \n");
print_Matrix(A, 3, 3);
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

// TODO - Fuction for augmenting matrices
// TODO - Function for un-augmenting matrices
// TODO - Function to implement Gauss-Jordan Alg