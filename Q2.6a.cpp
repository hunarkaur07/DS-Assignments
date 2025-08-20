#include <iostream>
using namespace std;

#define MAX 50   // maximum size for triplet table

// Function to transpose sparse matrix
void transposeSparse(int mat[][3], int transposed[][3]) {
    int rows = mat[0][0];      // number of rows
    int cols = mat[0][1];      // number of columns
    int nonZero = mat[0][2];   // number of non-zero elements


    // Fill first row of transpose with swapped rows & cols
    transposed[0][0] = cols;
    transposed[0][1] = rows;
    transposed[0][2] = nonZero;

    int k = 1; // index for transposed matrix
    // For each column of original
    for (int i = 0; i < cols; i++) {
        // Check all non-zero elements
        for (int j = 1; j <= nonZero; j++) {
            if (mat[j][1] == i) {   // if column matches
                transposed[k][0] = mat[j][1]; // swap row <-> col
                transposed[k][1] = mat[j][0];
                transposed[k][2] = mat[j][2]; // copy value
                k++;
            }
        }
    }
}

// Function to display sparse matrix
void displaySparse(int mat[][3]) {
    int nonZero = mat[0][2];
    cout << "\nRow\tCol\tValue\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << mat[i][0] << "\t" << mat[i][1] << "\t" << mat[i][2] << endl;
    }
}

int main() {
    int mat[MAX][3], transposed[MAX][3];
    int rows, cols, nonZero;

    // Input size of matrix
    cout << "Enter number of rows, columns, and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    // Fill first row of triplet (matrix info)
    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = nonZero;

    // Input non-zero elements
    cout << "Enter non-zero elements (row col value): \n";
    for (int i = 1; i <= nonZero; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    // Display original matrix
    cout << "\nOriginal Sparse Matrix (Triplet form): ";
    displaySparse(mat);

    // Transpose
    transposeSparse(mat, transposed);

    // Display transposed matrix
    cout << "\nTransposed Sparse Matrix (Triplet form): ";
    displaySparse(transposed);

    return 0;
}
