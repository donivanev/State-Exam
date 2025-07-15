#include <iostream>
#include <cmath>

// Решете задачата на езика C++. Отговорите на подточки 1А, 1Б, 1В и 1Г трябва да съвпадат с това, което би извела програмата.
// При несъответствие отговорът се оценява с нула точки. Решението на подточка 1Д трябва да бъде технически издържано (например
// не бива да изтича памет, трябва да се спазват добрите практики за структуриране на програмата и т.н.). Ако решението съдържа
// сериозни грешки, то се оценява с нула точки.

// А) Какъв ще бъде изходът от изпълнението на следния фрагмент:
int calc(int a[5])
{
    int sum = 8;
    for (int i = 0; a[i]; ++i) // докато a[i] != 0
        sum += i;
    return sum;
}

int a[7] = {1, 2, 3}; // 1, 2, 3, 0, 0, 0, 0
std::cout << calc(a);

// Отговор: 11

// Б) Какъв ще бъде изходът от изпълнението на следния програмен фрагмент?
char text[] = "hello", *p = text;
while (*p) std::cout << ++*p++;

// Изберете един от следните отговори:
// а) Грешка по време на компилация.
// б) Грешка по време на изпълнение.
// в) ifmmp                             - ВЯРНО
// г) el
// д) Безкраен цикъл.

// 1В) Какво ще изведе следният фрагмент (приемаме, че е част от валидна програма):
int *pt;
int a[3] = {4, 19, 13};
pt = &a[1];
pt += 1;
std::cout << *pt << std::endl;

// Отговор: 13

// 1Г) Какви ще бъдат стойностите на елементите на двата масива A и B след обръщението към функцията f?
void f(int * arr1, const int * arr2)
{
    int *p1 = arr1;
    const int *p2 = arr2;
    
    while(*p2 >= 0)
    {
        *p1++ = *p2++;
    }
}

void main()
{
    int A[4] = {-1, -2, -3, -4};
    int B[4] = {10, 20, 30, -1};
    
    f(A, B);
}

// Отговор:
// A[0] = 10 A[1] = 20 A[2] = 30 A[3] = -4 // 
// B[0] = -1 B[1] = -2 B[2] = -3 B[3] = -4 // 

// 1Д) Дадени са структура Point, описваща точка в декартова координатна система с координати x и y от тип float,
// и структура Circle, описваща окръжност с център center от тип Point и радиус r от тип float.
// Да се дефинира функция findRelativePosition, която определя относителната позиция на две дадени окръжности една
// спрямо друга. Резултатът от изпълнението на функцията е стойност от изброения тип:

// RelativePosition {NO_COMMON_POINTS, TOUCHING, INTERSECTING, SAME}. със следния смисъл:
// • NO_COMMON_POINTS: без общи точки
// • TOUCHING: допиращи се
// • INTERSECTING: пресичащи се
// • SAME: съвпадат

struct Point {
    float x;
    float y;
};

struct Circle {
    Point center;
    float r;
};

void findRelativePosition(Circle c1, Circle c2) {
    float distance = sqrt((c2.center.x - c1.center.x) * (c2.center.x - c1.center.x) + 
        (c2.center.y - c1.center.y) * (c2.center.y - c1.center.y));

    if (c1.center.x == c2.center.x && c1.center.y == c2.center.y && c1.r == c2.r) {
        std::cout << "Same";
    }
    else if (distance > c1.r + c2.r) {
        std::cout << "No common points";
    }
    else if (distance == c1.r + c2.r) {
        std::cout << "Touching";
    }
    else if (distance < c1.r + c2.r) {
        std::cout << "Intersecting";
    }
}

int main2() {

    Circle c1;
    c1.center.x = 2;
    c1.center.y = 3;
    c1.r = 5;

    Circle c2;
    c2.center.x = 3;
    c2.center.y = 8;
    c2.r = 5;

    findRelativePosition(c1, c2);

    return 0;
}