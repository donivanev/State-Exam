#include <iostream>
using namespace std;

void readMatrix(int* const* const matrix, int rows, int columns)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            cin >> matrix[i][j];
}

void printMatrix(const int* const* const matrix, int rows, int columns)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

void clearMatrixByRows(int** matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int** allocMatrixByRows(int rows, int columns)
{
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

int main() {

    int** m = nullptr;

    m = allocMatrixByRows(3, 4);
    if (!m) return 1;
    readMatrix(m, 3, 4);
    printMatrix(m, 3, 4);
    clearMatrixByRows(m, 3);

    return 0;
}