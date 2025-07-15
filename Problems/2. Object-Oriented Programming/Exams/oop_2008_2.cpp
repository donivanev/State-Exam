#include <iostream>
#include <vector>
using namespace std;

/*
Реализирайте абстрактен базов клас множество от числа от тип int, който има метод за проверка на принадлежност към множеството.
    • Реализирайте производен клас, който представява множеството от всички числа, които се делят без остатък на някакво предварително зададено
      в конструктора число.
    • Реализирайте и друг производен клас, който представя множество от числа чрез динамичен масив (който също се задава в конструктора).
    • Реализирайте външна за тези класове функция, която по зададен масив от множества и някакво число проверява дали то се съдържа в обединението
      на множествата от масива.
    • Демонстрирайте използването на тази функция в подходяща кратка програма.
*/

class SetOfInts {
    public:
        virtual bool is_in(int x) const = 0;
        virtual ~SetOfInts() {}
};

class Multiples : public SetOfInts {
    public:
        Multiples(int k) {
            divisor = k;
        }

        bool is_in(int x) const override {
            return x % divisor == 0;
        }

    private:
        int divisor;
};

class SetOfNums : public SetOfInts {
    public:
        SetOfNums(const vector<int>& nums) {
            numbers = nums;
        }

        bool is_in(int x) const override {
            for (int n : numbers) {
                if (n == x) {
                    return true;
                }
            }

            return false;
        }

    private:
        vector<int> numbers;
};

bool is_in_union(const vector<SetOfInts*>& sets, int x) {
    for (const auto& set : sets) {
        if (set->is_in(x)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    vector<SetOfInts*> sets;

    sets.push_back(new Multiples(3)); // всички числа, кратни на 3
    sets.push_back(new SetOfNums({2, 4, 7})); // конкретни числа

    int x = 7;
    cout << x << " is in union? " << (is_in_union(sets, x) ? "Yes" : "No") << endl;

    // Освобождаване на памет
    for (auto p : sets) {
        delete p;
    }

    return 0;
}