#include <iostream>
#include <vector>
using namespace std;

/*
Да се реализира абстрактен клас Function, представящ целочислена функция на една променлива.
Да се реализират негови наследници LinearFunction, CharacteristicFunction и Superposition, представящи съответно линейна функция,
характеристична функция на крайно множество от цели числа и суперпозиция на две функции, представени чрез обекти от тип Function.
Линейната функция от вида f(x) = ax + b се задава чрез коефициентите a и b.
Характеристичната функция на дадено множество е такава функция, която за елементите на множеството приема стойност 1, а за всички
останали стойности на аргумента – 0. Задава се чрез самото множество, представено чрез динамичен масив.
Суперпозиция на две функции f и g е такава функция h = f.g, за която h(x) = f(g(x)) за всяко x и се задава се чрез (указатели към)
два обекта от клас Function, представящи f и g.
За класовете да се реализират подходящи конструктори, метод за изчисляване на стойността на функцията и ако е необходимо – деструктори. 
*/

class Function {
    public:
        virtual int f(int x) const = 0;
        virtual ~Function() {}
};

class LinearFunction : public Function {
    public:
        LinearFunction(int a, int b) {
            a = a;
            b = b;
        }

        int f(int x) const override {
            return a * x + b;
        }

    private:
        int a, b;
};

class CharacteristicFunction : public Function {
    public:
        CharacteristicFunction(const vector<int>& values) {
            set = values;
        }

        int f(int x) const override {
            for (int val : set) {
                if (val == x) {
                    return 1;
                }
            }
            
            return 0;
        }
        
    private:
        vector<int> set;
};

class Superposition : public Function {
    public:
        Superposition(Function* f, Function* g) {
            outer = f;
            inner = g;
        }
    
        int f(int x) const override {
            return outer->f(inner->f(x));
        }
    
        ~Superposition() override {
            delete outer;
            delete inner;
        }
    
    private:
        Function* outer, *inner;
};    

int main() {

    // f(x) = 2x + 3
    Function* linear = new LinearFunction(2, 3);

    // Характеристична функция на множеството {1, 3, 5}
    Function* characteristic = new CharacteristicFunction({1, 3, 5});

    // Суперпозиция: h(x) = linear(characteristic(x)) = 2 * characteristic(x) + 3
    Function* composed = new Superposition(linear, characteristic);

    for (int x = 0; x <= 6; ++x) {
        cout << "h(" << x << ") = " << composed->f(x) << endl;
    }

    delete composed; // освобождава рекурсивно паметта

    return 0;
}