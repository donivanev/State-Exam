#include <iostream>
#include <vector>

/*
Класовете и шаблоните Inc, Square, Sum и Max описват едноместни функции от тип 𝑓 ∶ 𝑇 → 𝑇.
Видът на конкретната функция се дефинира от метода value в съответния клас.
Класът Inc представя функцията 𝑓 ∶ double → double, 𝑓 (𝑥) = 𝑥 + 1. Класът Square представя функцията 𝑓 ∶ double → double, 𝑓 (𝑥) = 𝑥².
Шаблонът на клас Sum представя функцията 𝑓 ∶ 𝑇 → 𝑇 , 𝑓 (𝑥) = 𝑓₁(𝑥) + ... + 𝑓ₖ(𝑥), където 𝑓₁(𝑥), ..., 𝑓ₖ(𝑥), 𝑘 ≥ 0 е списък от
функции от тип 𝑓ᵢ ∶ 𝑇 → 𝑇 . Дадена функция се добавя към списъка с функции на обект от клас Sum<T> чрез метода addFunction.
Шаблонът на клас Max представя функцията 𝑓 ∶ 𝑇 → 𝑇 , 𝑓 (𝑥) = 𝑚𝑎𝑥{𝑓₁(𝑥), ..., 𝑓ₖ(𝑥)}, където 𝑓₁(𝑥), ..., 𝑓ₖ(𝑥), 𝑘 > 0 е списък от
функции от тип 𝑓ᵢ ∶ 𝑇 → 𝑇 . Дадена функция се добавя към списъка с функции на обект от клас Max<T> чрез метода addFunction.
Function е шаблон на абстрактен клас, който е базов за Inc, Square, Sum и Max. Функцията main въвежда от стандартния вход
числото 𝑥 и извежда най-голямата измежду стойностите 𝑥 + 1, 𝑥² и 𝑥² + 𝑥 + 1.
Да се попълнят липсващите части в програмата. Приемаме, че класовете Sum и Max не е нужно да правят копие на подадените им функции.
*/

template <typename T>
class Function {
    public:
        /*____________*/ T value(T) const /*____________*/ // virtual, = 0
};

class Inc : /*____________*/ { // public Function
    public:
        double value(double x) const { return x + 1; }
};

class Square : /*____________*/ { // public Function
    public:
        double value(double x) const { return x * x; }
};

/*________________________*/ // template <typename T>
class Max : /*____________*/ { // public Function
    private:
        std::vector</*____________*/> functions; // Function<T>*
    public:
        void addFunction(/*____________*/ f) { functions.push_back(f); } // Function<T>*
        T value(T x) const {
            if(/*____________*/) // functions.size() < 1
                throw "Function list is empty!";
            //...???
            return /*____________*/; // result
        }
};

/*________________________*/ // template <typename T>
class Sum : /*____________*/ { // public Function
    private:
        std::vector</*____________*/> functions; // Function<T>*
    public:
        void addFunction(/*____________*/ f) { functions.push_back(f); } // Function<T>*
        T value(T x) const {
            //...???
            return /*____________*/; // result
        }
};

int main()
{
    Inc i;
    Square sq; 
    Sum<double> s;
    //(x+1)+(x*x)
    s.addFunction(&i);
    s.addFunction(&sq);

    Max<double> m;
    //{x+1, x*x, (x+1)+(x*x)}
    m.addFunction(&i);
    m.addFunction(&sq);
    m.addFunction(&s);

    double x; std::cin >> x;
    std::cout << m.value(x) << std::endl;
}