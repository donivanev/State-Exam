#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

/* 
Разредена матрица представлява матрица с голяма размерност, за която малък брой от елементите са ненулеви(*).
    • Опишете с думи подходяща структура от данни, в която да съхранявате такава матрица.
    • Напишете функция, която приема като аргументи две разредени матрици от реални числа, представени по описания от вас начин,
    и връща като резултат тяхната сума, отново представена по този начин.
    • Демонстрирайте тази функция в кратка програма.
(*) За матрица с голяма размерност приемаме, например, матрица с размерност 106 × 106 и брой на ненулевите елементи от порядъка на 104.
Разрешава се използването на стандартните за езика библиотеки.
*/

typedef pair<int, int> Position;

struct SparseMatrix {
    int rows, cols;
    map<Position, double> values; // само ненулевите
};

SparseMatrix addSparse(const SparseMatrix& A, const SparseMatrix& B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        throw invalid_argument("Размерностите на матриците не съвпадат.");
    }

    SparseMatrix result;
    result.rows = A.rows;
    result.cols = A.cols;
    result.values = A.values; // копиране на първата

    for (const auto& pair : B.values) {
        const auto& pos = pair.first;
        const auto& val = pair.second;
        result.values[pos] += val;

        // ако стойността стане 0, премахваме я
        if (result.values[pos] == 0.0) {
            result.values.erase(pos);
        }
    }

    return result;
}

void printSparse(const SparseMatrix& M) {
    cout << "Размери: " << M.rows << " x " << M.cols << endl;
    cout << "Ненулеви елементи:" << endl;
    
    for (const auto& pair : M.values) {
        const auto& pos = pair.first;
        const auto& val = pair.second;

        cout << "  (" << pos.first << ", " << pos.second << ") = " << fixed << setprecision(2) << val << endl;
    }
}

int main() {
    SparseMatrix A{5, 5};
    A.values[{0, 0}] = 1.5;
    A.values[{2, 3}] = -2.0;
    A.values[{4, 1}] = 3.0;

    SparseMatrix B{5, 5};
    B.values[{0, 0}] = 2.5;
    B.values[{2, 3}] = 2.0;     // ще се занули
    B.values[{1, 1}] = 4.0;

    cout << "Матрица A:\n";
    printSparse(A);

    cout << "\nМатрица B:\n";
    printSparse(B);

    SparseMatrix C = addSparse(A, B);

    cout << "\nСума A + B:\n";
    printSparse(C);

    return 0;
}