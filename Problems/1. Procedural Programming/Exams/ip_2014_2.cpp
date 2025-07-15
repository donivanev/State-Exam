#include <iostream>
#include <iomanip>
using namespace std;

/*
Дадени са координатите на N-точки, които са записани в масивите float x[N], y[N] по следния начин: координатите на i-тата точка са (x[i], y[i]).
Напишете функция square, която получава като аргументи броя на точките N и два масива X и Y съдържащи координатите им и извежда на екрана
координатите на центъра и страната на най-малкия квадрат със страни успоредни на координатните оси, който обхваща всички дадени точки
(всички дадени точки са във вътрешността му или на страните му).
*/

void square(int N, float x[], float y[]) {
    // 1. Намираме минимални и максимални стойности по x и y
    float minX = x[0], maxX = x[0];
    float minY = y[0], maxY = y[0];

    for (int i = 1; i < N; i++) {
        if (x[i] < minX) minX = x[i];
        if (x[i] > maxX) maxX = x[i];
        if (y[i] < minY) minY = y[i];
        if (y[i] > maxY) maxY = y[i];
    }

    // 2. Страната на най-малкия квадрат е най-голямото от двете разстояния
    float width = maxX - minX;
    float height = maxY - minY;
    float side = (width > height) ? width : height;

    // 3. Намираме центъра на квадрата
    float centerX = (minX + maxX) / 2;
    float centerY = (minY + maxY) / 2;

    // 4. Извеждаме резултата
    cout << fixed << setprecision(2); // форматиране до 2 знака
    cout << "Center: (" << centerX << ", " << centerY << ")\n";
    cout << "Side: " << side << endl;
}

int main() {

    const int N = 4;
    float x[N] = {1.0, 2.0, 5.0, 4.0};
    float y[N] = {1.0, 3.0, 2.0, 6.0};

    square(N, x, y);

    return 0;
}