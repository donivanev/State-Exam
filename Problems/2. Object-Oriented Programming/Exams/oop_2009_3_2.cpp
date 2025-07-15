#include <iostream>
#include <vector>
using namespace std;

/*
Да се реализира абстрактен клас Sequence, представящ безкрайна редица от числа и метод за достъп до нейните елементи (по пореден номер).
Да се реализират класовете ArithmeticProgression, PeriodicSequence и InterleavedSequence, наследници на класа Sequence,
които представят съответно аритметична прогресия, периодична редица и комбинация на две редици.
Периодична редица е такава безкрайна редица от числа, която се получава като последователно повторение на крайна редица от числа безкраен брой пъти.
Комбинация на две редици a₁, a₂, ..., aₙ ... и b₁, b₂, ..., bₙ, ... е редицата a₁, b₁, a₂, b₂, ..., aₙ, bₙ, ...
За класовете да се реализират подходящи конструктори, мутатори (методи за промяна на стойността на полетата) и ако е необходимо – деструктори. 
*/

class Sequence {
    public:
        virtual int get(int i) const = 0;
        virtual ~Sequence() {}
};

// Аритметична прогресия: елемент на място index: a + index * d
class ArithmeticProgression : public Sequence {
    public:
        ArithmeticProgression(int start, int step) {
            a = start;
            d = step;
        }
    
        int get(int index) const override {
            return a + index * d;
        }
    
        void setStart(int newStart) {
            a = newStart;
        }
        void setStep(int newStep) {
            d = newStep;
        }
    
    private:
        int a, d;
    };

// Периодична редица: циклично повтаря елементите от вектор
class PeriodicSequence : public Sequence {
    public:
        PeriodicSequence(const vector<int>& elems) : elements(elems) {}
    
        int get(int index) const override {
            if (elements.empty()) return 0;
            return elements[index % elements.size()];
        }
    
        void setElement(int i, int value) {
            if (i >= 0 && i < elements.size()) {
                elements[i] = value;
            }
        }
    
    private:
        vector<int> elements;
    };

// Комбинация от две редици: a1, b1, a2, b2, ...
class InterleavedSequence : public Sequence {
    public:
        InterleavedSequence(Sequence* first, Sequence* second)
            : seq1(first), seq2(second) {}
    
        int get(int index) const override {
            if (index % 2 == 0) {
                return seq1->get(index / 2);
            } else {
                return seq2->get(index / 2);
            }
        }
    
        ~InterleavedSequence() override {
            delete seq1;
            delete seq2;
        }
    
    private:
        Sequence* seq1;
        Sequence* seq2;
    };
int main() {
    Sequence* ap = new ArithmeticProgression(1, 3); // 1, 4, 7, 10, ...
    Sequence* periodic = new PeriodicSequence({10, 20, 30}); // 10, 20, 30, 10, ...

    Sequence* interleaved = new InterleavedSequence(ap, periodic);

    cout << "Първите 10 елемента на преплетената редица:" << endl;

    for (int i = 0; i < 10; ++i) {
        cout << interleaved->get(i) << " ";
    }
    
    cout << endl;

    delete interleaved; // Изтрива и вложените seq1 и seq2

    return 0;
}