#include <iostream>

// Разгледайте дадената по-долу програма. В полето за отговор напишете какво ще изведе тя.

class A {
    public:
        A() { prn('c'); }
        ~A() { prn('d'); }
    
    virtual void prn(char ch) const {
        std::cout << 'A' << ch << ';';
    }
};

class B : public A {
    public:
        B() { prn('c'); }
        ~B() { prn('d'); }

    virtual void prn(char ch) const {
        std::cout << 'B' << ch << ';';
    }
};

int main() {
    A* obj = new B;
    obj->prn('p');
    delete obj;
}

// Отговор: ______________________________

// Срещу всяко от твърденията напишете „Да“, ако то е вярно, или „Не“, ако е невярно.

// А) Конструкторът на един клас може да бъде статичен. - 
// Б) Деструкторът на един клас може да бъде статичен. - 
// В) В статична член-функция на даден клас можем да достъпваме както статичните, така и нестатичните член-променливи на класа. - 
// Г) В статична член-функция на даден клас можем да направим обръщение към виртуална член-функция на същия клас без да има създаден обект. - 
// Д) Във виртуална функция на даден клас можем да направим обръщение към статична член-функция на същия клас. - 
// Е) Ако в един абстрактен клас има член-функция, тя задължително трябва да бъде виртуална. - 

// Довършете програмата (на подчертаните места) така, че да бъде синтактично коректна и да спазва принципите на ООП в C++.

class Item {
    std::string m_label;
    
    public:
        Item(std::string t) : m_label(t) {}

    /*___________*/ ~Item() {}

    const std::string& label() const {
        return m_label;
    }
};

/*________________*/ <typename T>
class Box : public Item{
    /*______*/ m_contents;
    
    public:
        Box(std::string label, const T& contents) : Item(/*_____________*/) {
            m_contents = new T(/*_________________*/);
        }

        Box(const Box&) = delete;
        
        Box& operator=(const Box&) = delete;
        
        /*___________*/ ~Box() { delete m_contents; }
    
        T& contents() { return /*_______________*/; }
};

Box<int>* createRandomIntBox() {
    int randomValue = rand() % 100 + 1;

    return /*______________________________*/("random box", randomValue);
}

Box<int>* toIntBox(Item* p) {
    return dynamic_cast<Box<int>*>(p);
}

int main() {
    Item* p = createRandomIntBox();
    toIntBox(p)->contents() = 42;
    std::cout << "Box {" << "\n Label: " << p->label() << "\n Contents: " << toIntBox(p)->contents() << "\n}\n";
    delete p;
}