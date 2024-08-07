#include <iostream>
using namespace std;

class Shape {
    public:
        virtual ~Shape() = default;

        // Pure virtual function to calculate the area of the shape
        virtual double area() const = 0;

        // Pure virtual function to get the type of shape
        virtual const char* getType() const = 0;
};

class Triangle : public Shape {
    private:
        double base;
        double height;

    public:
        Triangle(double b, double h) : base(b), height(h) {}

        //Polymorphism
        double area() const override {
            return 0.5 * base * height;
        }

        //Polymorphism
        const char* getType() const override {
            return "Triangle";
        }
};

class Rectangle : public Shape {
    private:
        double length;
        double width;

    public:
        Rectangle(double l, double w) : length(l), width(w) {}

        //Polymorphism
        double area() const override {
            return length * width;
        }

        //Polymorphism
        const char* getType() const override {
            return "Rectangle";
        }
};

int main() {

    Triangle t(4.0, 6.0);
    Rectangle r(3.0, 8.0);

    cout << "Shape type: " << t.getType() << endl;
    cout << "Area: " << t.area() << endl;
    cout << "Shape type: " << r.getType() << endl;
    cout << "Area: " << r.area() << endl;

    return 0;
}