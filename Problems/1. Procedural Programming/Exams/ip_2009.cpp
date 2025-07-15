#include <iostream>
#include <cmath>
using namespace std;

/*
Да се напише програма, която въвежда от клавиатурата правоъгълна матрица от реални числа с 5 реда и 10 стълба.
Програмата да извежда на екрана текста "yes" в случай, че въведената матрицата има поне два различни линейно зависими реда и "no" в противен случай.
*/

int readMatrix(double** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(double** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double** allocateMatrix(int n, int m) {
    double** matrix = new double*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new double[m];
    }

    return matrix;
}

// Проверка дали два реда са линейно зависими
bool areLinearlyDependent(double* row1, double* row2, int m) {
    double lambda = 0;
    bool found = false;

    for (int j = 0; j < m; j++) {
        if (row1[j] == 0 && row2[j] == 0) {
            ; // пропускаме и продължаваме – съвпадат, но не ни дават λ
        }
        else if (row1[j] == 0 || row2[j] == 0) {
            return false; // единият е 0, другият не – не са зависими
        }
        else {
            double currentLambda = row2[j] / row1[j];
            
            if (!found) {
                lambda = currentLambda;
                found = true;
            }
            else {
                if (abs(currentLambda - lambda) > 1e-6) {
                    return false;
                }
            }
        }
    }

    return found; // ако не е намерен λ (само нули), връща false
}

// Проверка за линейно зависими редове
bool hasLinearlyDependentRows(double** matrix, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            if (areLinearlyDependent(matrix[i], matrix[k], m)) {
                return true;
            }
        }
    }

    return false;
}

void deleteMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++)
        delete matrix[i];
    delete[] matrix;
}

int main() {
    
    double** matrix = nullptr;
    matrix = allocateMatrix(5, 10);

    readMatrix(matrix, 5, 10);
    printMatrix(matrix, 5, 10);
    
    hasLinearlyDependentRows(matrix, 5, 10) ? cout << "yes" : cout << "no";

    deleteMatrix(matrix, 5);

    return 0;
}