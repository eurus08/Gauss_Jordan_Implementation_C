# Gauss-Jordan Solver (gj.c)

## 📖 Overview
This project provides a **C implementation of the Gauss-Jordan elimination algorithm** to solve systems of linear equations (SLEs) of the form:

\[ AX = b \]

Additionally, if \( b \) is the identity matrix, the program computes the **inverse of matrix A**.

---

## 🚀 Features
- Solve systems of linear equations.
- Compute matrix inverses.
- Modular design with reusable functions.
- Augments matrices internally for solving.
- Simple output formatting for matrix display.

---

## 🛠️ How to Compile and Run

```bash
# Compile
gcc gauss_jordan.c -o gauss_jordan.out
# Run
./gauss_jordan.out
```

You should see printed matrices for A, b, and the solution.

---

## 📜 Algorithms


#### Algorithm: Print Matrix to `stdout`

**Input:** Matrix array, number of rows, number of columns  
**Output:** Printed matrix

##### Steps:
1. For each row `i` from `0` to `numRows-1`, do:
   - For each column `j` from `0` to `numCols-1`, do:
     - Print `matrix[i][j]` formatted.
   - Print newline.

---

#### Algorithm: Gauss-Jordan Algorithm for Matrix reduction (to RREF)

**Input:** Augmented matrix, number of rows, number of columns  
**Output:** Matrix in reduced row echelon form (RREF)

##### Steps:
1. For each pivot row `i` from `0` to `numRows-1`, do:
   - Set pivot element ← `matrix[i][i]`.
   - Normalize row `i` by dividing by the pivot element .
   - For each other row `j` (where `j ≠ i`), do:
     - Subtract a multiple of row `i` from row `j` to eliminate `matrix[j][i]`.

---

#### Algorithm: Augment two matrices

**Input:** Empty augmented matrix, matrix A, matrix b, dimensions  
**Output:** Augmented matrix [A|b]

##### Steps:
1. For each row `i` from `0` to `numRows-1`, do:
   - For each column `j` from `0` to `numCols-1`, do:
     - If `j` corresponds to b's columns:
       - Copy corresponding element from `b` into `augMatrix` 
     - Else:
       - Copy corresponding element from `A` into `augMatrix`.

---

#### Algorithm: Extract solution from Augmented matrix

**Input:** Augmented matrix [A|b], dimensions  
**Output:** Extracted matrix b

##### Steps:
1. For each row `i` from `0` to `numRows-1`, do:
   - For each column `j` from `0` to `numCols-1`, do:
     - If `j` corresponds to b's columns:
       - Copy element from `augMatrix` into `b`.

---

#### Algorithm: Solve System of Equation

**Input:** Matrices A and b with dimensions  
**Output:** Solution matrix b or A\(^{-1}\)

##### Steps:
1. Compute dimensions for the augmented matrix.
2. Create `augMatrix` of appropriate size.
3. Call `augment_Matrices` to combine A and b into `augMatrix`.
4. Call `gauss_jordan` to reduce `augMatrix` to RREF.
5. Call `un_augment_Matrix` to extract the solution into b.




