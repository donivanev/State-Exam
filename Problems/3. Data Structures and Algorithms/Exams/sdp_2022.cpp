#include <iostream>
using namespace std;

// В тази задача едносвързан списък ще представяме чрез указател към първата му кутия, а кутиите му – чрез структури от вида:
struct node {
    int data; // числов елемент
    node* next; // следваща кутия в списъка или nullptr, ако няма
    
    node(int data, node* next = nullptr) : data(data), next(next) {}
};

//1) Да се довърши кодът на функциите (в подчертаните места) така, че sortListAscending да сортира в нарастващ ред елементите
// на списъка lst. Ако списъкът е празен, функцията да не прави нищо.
node* min(node* lst) {
    node* result = lst;
    
    for (; lst; lst = lst->next) {
        if (result->data /*____*/ /*________________*/) // > lst->data
            result = lst;
    }
    
    return result;
}

void sortListAscending(node* lst) {
    while (/*_________________*/) { // lst
        swap(/*_________________*/, min(lst)->data); // lst->data
        lst = /*_________________*/; // lst->next
    }
}

// 2) Разгледайте кода на функцията mystery:
void mystery(node* lst) {
    while (lst && lst->next) {
        lst->data += lst->next->data;
        lst->data /= 2;
        node* tmp = lst->next;
        lst = lst->next = lst->next->next;
        delete tmp;
    }
}

// Под дадения долу фрагмент да се напише точно какво ще изведе на стандартния изход.
node* e = new node(56);
node* d = new node(20, e);
node* c = new node(10, d);
node* b = new node(4, c);
node* a = new node(2, b);
mystery(a);
while (a) {
    std::cout << "[" << a->data << "] -> ";
    a = a->next;
}
std::cout << "NULL";

// [3] -> [15] -> [56] -> NULL

// 3) Възлите на двоично дърво представяме чрез структури от вида:
struct tnode {
    int data; // числов елемент
    tnode* left; // ляв наследник
    tnode* right; // десен наследник
    // указателите са nullptr, ако възелът няма съответния наследник
};

// Да се попълнят празните места в кода на функцията toArray. Тя получава корена t на двоично наредено дърво. Функцията да
// копира елементите му в масива out така, че да са сортирани в нарастващ ред. Това да става чрез обхождане ляво-корен-дясно
// (inorder). За целите на задачата допускаме, че в out има достатъчно място.
int* toArray(tnode* t, int* out) {
    if (/*____________*/) { // !t
        return /*____________*/; // out
    }
    else {
        int* p = toArray(/*____________*/, out); // t->left
        *p = t->data;
        return toArray(/*___________*/, /*___________*/); // t->right, p + 1
    }
}