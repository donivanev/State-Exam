// Свързан списък ще представяме с верига от обекти от следната структура, динамично заделени с new. За последния елемент на списъка указателят
// next има стойност nullptr. Приемаме, че за типа Type са дефинирани нужните конструктори и оператори.

template <typename Type>
struct node {
    const Type data;
    node<Type>* next;
};

// Да се реализират следните функции, получаващи като аргумент указател към първия елемент на списък и връщащи указател към началото на резултатния списък.
// Не се позволява използване на алгоритми и структури от данни от стандартната библиотека.

// а) Функция, която обръща свързан списък. Тя трябва да използва константно количество допълнителна памет и да е с линейна сложност.

template <typename Type>
node<Type>* reverse(node<Type>* first) {
    node<Type>* prev = nullptr, *current = first;

    while (current) {
        node<Type>* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// б) Функция, която премахва от списъка всички елементи, равни на първия при сравнение с ==, но без него.
// Тя трябва да използва константно количество допълнителна памет и да е с линейна сложност.

template <typename Type>
node<Type>* filter(node<Type>* first) {
    if (!first)
        return nullptr;

    const Type& target = first->data;
    node<Type> *prev = first, *current = first->next;

    while (current) {
        if (!(current->data != target)) {  // вместо ==, ползваме отрицание на !=
            prev->next = current->next;
            delete current;
            current = prev->next;
        } 
        else {
            prev = current;
            current = current->next;
        }
    }

    return first;
}

// в) Функция, която подрежда елементите на списъка във възходящ ред. Тя трябва да има асимптотична времева сложност в средния случай по-добра от O(n²).
// Опишете накратко с текст какъв алгоритъм сте реализирали, каква е неговата времева сложност и каква е сложността му по памет.

template <typename Type>
node<Type>* merge(node<Type>* a, node<Type>* b) {
    if (!a)
        return b;
    if (!b)
        return a;

    node<Type>* result = nullptr;

    if (a->data < b->data) {
        result = a;
        result->next = merge(a->next, b);
    }
    else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

template <typename Type>
void splitList(node<Type>* source, node<Type>** frontRef, node<Type>** backRef) {
    node<Type> *slow = source, *fast = source->next;

    while (fast) {
        fast = fast->next;

        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

template <typename Type>
node<Type>* sort(node<Type>* first) {
    if (!first || !first->next)
        return first;

    node<Type>* a = nullptr, *b = nullptr;

    splitList(first, &a, &b);

    a = sort(a);
    b = sort(b);

    return merge(a, b);
}