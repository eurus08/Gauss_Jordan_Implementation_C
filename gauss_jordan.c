/* ######### gauss_jordan.c #########
Author: eurus
Date: May 06, 2025
Description: C implementation of the Gauss Jordan Algorithm 
For Solve a system of equations AX =b.
if b is the identity element then its finds the A^-1
*/


// Header
#include <stdio.h>


// Prototypes
void print_Matrix(double *matrix, int numRows, int numCols);
void augment_Matrices(double *augMatrix, double *A, int numRows, double *b, int numCols, int b_cols);
void un_augment_Matrix(double *augMatrix, int numRows, int numCols, double *b, int b_cols);
void gauss_jordan(double *matrix, int numRows, int numCols);
void SLE_solver(double *A, int A_rows, int A_cols, double *b, int b_rows, int b_cols, double *solution);


// Main function
int main(int argc, char *argv[]){


//Create matrices
double A[9] = {4,5,3,7,9,5,5,6,7};
double b[9] = {1,0,0,0,1,0,0,0,1};
double A_inverse[9];


// //Augment matrix
// augment_Matrices(Aug, A, 3, b, 6, 3);

// //Reduce augmented matrix to RREF
// gauss_jordan(Aug, 3, 6);

// Solve for Inverse of A
SLE_solver(A, 3, 3, b, 3, 3, A_inverse);


// print matrices
printf("Matrix A \n");
print_Matrix(A, 3, 3);
printf("\n \n");

printf("Matrix b \n");
print_Matrix(b, 3, 3);
printf("\n \n");

printf("Matrix A^(-1) \n");
print_Matrix(A_inverse, 3, 3);
printf("\n \n");


// //un-augment matrix
// un_augment_Matrix(Aug, 3, 6, un_Aug, 3);

// // print matrices
// printf("Matrix un_Aug \n");
// print_Matrix(un_Aug, 3, 3);
// printf("\n \n");


return 0;
}


// Subroutines

// Function to print a matrix to stdout
void print_Matrix(double *matrix, int numRows, int numCols){

    for (int i = 0; i < numRows; i++){
        for (int j = 0; j< numCols; j++){
            printf("%6.2lf\t", matrix[i*numCols + j]);
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

// Function to reduce a matrix to RREF using Gauss-Jordan Elimination 
void gauss_jordan(double *matrix, int numRows, int numCols){

    for (int i = 0; i < numRows; i++){//loop through all rows

        // Set pivot element
        double pivot = *(matrix+(i*numCols + i));

        //Normalize each element in for i
        for (int j = 0; j < numCols; j++){//loop through all columns
            *(matrix+(i*numCols + j)) /= pivot; 
        }

        //Apply row reduction to all rows except pivot row
        for (int j = 0;j < numRows; j++){///loop through all rows
            if (j == i) continue; //except pivot row

            // set row reduction factor 
            double factor =   *(matrix+(j*numCols + i));

            for (int k = 0; k < numCols; k++){
                *(matrix+(j*numCols + k)) -= factor * *(matrix+(i*numCols + k));
            }
        }
    }
}

//TODO - Write a partial pivoting form of the Gauss-Jordan function 



// Function to solve a system of equation A|b or find A^-1 if b is the identity matrix 
void SLE_solver(double *A, int A_rows, int A_cols, double *b, int b_rows, int b_cols, double *solution){

    // Create and populate augmented matrix [A|b]
    int numRows  = A_rows; // Number of rows for augmented matrix
    int numCols = A_cols + b_cols; // Number of columns for augmented matrix

    double augMatrix[numRows * numCols];//create augmented matrix array
    augment_Matrices(augMatrix, A, numRows, b, numCols, b_cols);
    
    // //Print augmented matrix
    // print_Matrix(augMatrix, numRows, numCols);

    // Reduce augmented matrix to RREF using gauss jordan approach
    gauss_jordan(augMatrix, numRows, numCols);

    //Extract right side from augmented matrix
    un_augment_Matrix(augMatrix, numRows, numCols, solution,b_cols);
}