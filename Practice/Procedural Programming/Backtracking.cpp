#include <iostream>
using namespace std;

bool findTreasure(int m[][6], int n, int x, int y) {
    // out of the matrix, step on a wall or step on already traversed position
    if (x < 0 || y < 0 || x == n || y == n || m[x][y] == 1 || m[x][y] == 3) {
        return false;
    }

    // target found
    if (m[x][y] == 2) {
        return true;
    }

    // mark posistion as traversed
    m[x][y] = 3;

    // step left
    if (findTreasure(m, n, x - 1, y)) {
        return true;
    }
    // step right
    if (findTreasure(m, n, x + 1, y)) {
        return true;
    }
    // step up
    if (findTreasure(m, n, x, y + 1)) {
        return true;
    }
    // step bottom
    if (findTreasure(m, n, x, y - 1)) {
        return true;
    }
    
    // target not found
    return false;
}

int main() {
    int m[6][6] = {
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 1, 0 },
        { 0, 1, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 1, 1, 0, 0, 0, 2 }
    };

    cout << findTreasure(m, 6, 0, 0);
}