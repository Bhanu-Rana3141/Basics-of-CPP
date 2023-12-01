#include<iostream>
using namespace std;

class Animal{

    public:
        void bark() {
            cout << "barking" << endl;
        }
};

class Human{

    public:
        void speak() {
            cout << "speaking" << endl;
        }
};

// multiple inheritance -> child class inherting from 2 parent classes
class Hybrid : public Animal, public Human {
    
};

int main() {

    Hybrid obj;
    obj.bark();
    obj.speak();

    return 0;
}