#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
Магазин продава два типа артикули – бройни и количествени. Една покупка на бройен артикул се задава чрез името му, единичната цена и броя закупени
артикули, който е цяло число, а една покупка на количествен артикул – чрез името му, цената за килограм и закупеното количество – реално число,
което показва колко килограма са закупени.

а) Да се реализира абстрактен базов клас, който обединява общата функционалност за двата вида покупки и има виртуален метод за пресмятане на
стойността на една покупка. Да се реализират два производни класа, представляващи покупките на двата типа артикули.
б) Да се реализира клас касова_бележка. Бележката трябва да има номер и масив от покупки. В класа за касова бележка да има метод, който пресмята
общата стойност на всички покупки от масива.
в) Демонстрирайте използването на класовете в подходяща кратка програма.
*/

class Purchase {
    public:
        virtual double calculateValue() const = 0;
        virtual ~Purchase() {}
};

class ProductPerUnit : public Purchase {
    public:
        ProductPerUnit(const char* n, int i, double p) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
            price = p;
            items = i;
        }

        double calculateValue() const override {
            return items * price;
        }

        ~ProductPerUnit() override {
            delete[] name;
        }

    private:
        char* name;
        double price;
        int items;
};

class ProductPerKg : public Purchase {
    public:
        ProductPerKg(const char* n, double p, double b) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
            pricePerKg = p;
            boughtKgs = b;
        }

        double calculateValue() const override {
            return boughtKgs * pricePerKg;
        }

        ~ProductPerKg() override {
            delete[] name;
        }

    private:
        char* name;
        double pricePerKg;
        double boughtKgs;
};

class Receipt {
    public:
        Receipt(int n) {
            number = n;
        }

        void addPurchase(Purchase* p) {
            products.push_back(p);
        }

        double calculateTotalValue() const {
            double sum = 0.0;

            for (const auto& p : products) {
                sum += p->calculateValue();
            }
            
            return sum;
        }

        ~Receipt() {
            for (auto p : products) {
                delete p;
            }
        }

    private:
        int number;
        vector<Purchase*> products;
};

int main() {
    Receipt r(1);

    Purchase* eggs = new ProductPerUnit("Eggs", 6, 1.2);
    Purchase* cheese = new ProductPerKg("Cheese", 15.0, 1.5);

    r.addPurchase(eggs);
    r.addPurchase(cheese);

    cout << "Total: " << r.calculateTotalValue() << endl;

    return 0;
}