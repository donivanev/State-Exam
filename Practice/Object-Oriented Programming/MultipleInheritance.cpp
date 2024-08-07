#include <iostream>
using namespace std;

class Device {
    public:
        virtual ~Device() = default;

        // Pure virtual function to start the device
        virtual void start() const = 0;

        // Pure virtual function to get the type of device
        virtual const char* getType() const = 0;
};

class Phone : virtual public Device {
    public:
        void start() const override {
            cout << "Starting the phone!" << endl;
        }

        const char* getType() const override {
            return "Phone";
        }
};

class Laptop : virtual public Device {
    public:
        void start() const override {
            cout << "Starting the laptop!" << endl;
        }

        const char* getType() const override {
            return "Laptop";
        }
};

// Mulitple inheritance
class Smartphone : public Phone, public Laptop {
    public:
        void start() const override {
            Phone::start();
            Laptop::start();
        }

        const char* getType() const override {
            return "Smartphone";
        }
};

int main() {

    Smartphone s;

    cout << "Device type: " << s.getType() << endl;
    s.start();

    return 0;
}