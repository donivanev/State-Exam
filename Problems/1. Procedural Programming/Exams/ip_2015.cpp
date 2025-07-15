#include <iostream>
using namespace std;

/*
Дадена е float матрица img с размери М ≤ 10 реда и N ≤ 10 стълба. Напишете функция subsample, която получава като аргументи
M, N и img и извежда на екрана матрица s с размери (М+1)/2 и (N+1)/2 (при целочислено деление), всеки елемент s[i][j] на която
е равен на средно аритметичното от всички елементи img[y][x], такива че i*2 ≤ y ≤ i*2+1 и j*2 ≤ x ≤ j*2+1.
Например, при матрица img, представена таблично по следния начин:
1.0 2.0 3.0
4.5 6.5 7.5
функцията да извежда на екрана: 3.5 5.25
*/

void readMatrix(float** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(float** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

float** allocateMatrix(int n, int m) {
    float** matrix = new float*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new float[m];
    }
    
    return matrix;
}

void subsample(float** img, int n, int m) {
    float** s = nullptr;
    s = allocateMatrix((n + 1) / 2, (m + 1) / 2);
    int x = 0, y = 0;

    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < (m + 1) / 2; j++) {
            int yStart = i * 2, xStart = j * 2;
            float sum = 0.0;
            int count = 0;

            for (int y = yStart; y < min(yStart + 2, n); y++) {
                for (int x = xStart; x < min(xStart + 2, m); x++) {
                    sum += img[y][x];
                    count++;
                }
            }

            s[i][j] = sum / count;
        }
    }
    
    printMatrix(s, (n + 1) / 2, (m + 1) / 2);
    clearMatrix(s, (n + 1) / 2);
}

void clearMatrix(float** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    
    delete[] matrix;
}

int main() {
    
    int n = 0, m = 0;
    float** img = nullptr;

    cin >> n >> m;
    img = allocateMatrix(n, m);
    readMatrix(img, n, m);
    printMatrix(img, n, m);

    subsample(img, n, m);

    clearMatrix(img, n);

    return 0;
}