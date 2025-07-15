#include <iostream>
using std::cin;
using std::cout;

void readMatrix(int* const* const matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            cin >> matrix[i][j];
}

void printMatrix(const int* const* const matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

void clearMatrixByRows(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int** allocMatrixByRows(int rows, int columns) {
    int** matrix = new int* [rows];
    if (!matrix) return matrix;

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];

        if (!matrix[i]) {
            clearMatrixByRows(matrix, i);
            return nullptr;
        }
    }

    return matrix;
}

// Only for square matrix
void transpose(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void traverse(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) // main diagonal
            {
                // i <= j => above main diagonal
                // i >= j => under main diagonal
            }
            // if (i == n - j - 1) // anti diagonal
            // {
            //     i <= n - j - 1 => above anti diagonal
            //     i >= n - j - 1 => under anti diagonal
            // }
        }
    }
}

int main() {

    int** m = nullptr;

    m = allocMatrixByRows(3, 4);
    if (!m) return 1;
    readMatrix(m, 3, 4);
    printMatrix(m, 3, 4);
    clearMatrixByRows(m, 3);

    // Created in stack
    int matrix[2][3] = {{2, 4, 9}, {6, 9, 15}};

    // Partial creation in heap (array of pointers), do not use!
    int *arrOfPointers[3];
    arrOfPointers[0] = new int[4];
    arrOfPointers[1] = new int[4];
    arrOfPointers[2] = new int[4];

    // Pointer is created in stack
    int **heapMatrix;
    // This is created in heap
    heapMatrix = new int*[3];
    heapMatrix[0] = new int[4];
    heapMatrix[1] = new int[4];
    heapMatrix[2] = new int[4];

    return 0;
}