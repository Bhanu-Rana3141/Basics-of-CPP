/*
RUN TIME POLYMORPHISM -> function/method overridding
*OVERRIDING :  child class m jo parent class ka function h usko apni need k according implement karna

*/

#include<iostream>
using namespace std;

class Animal{
    public:
        Animal() {
            cout << "I am inside animal constructor" << endl;
        }

        virtual void speak() {
            cout << "speaking" << endl;
        }
};

class Dog : public Animal {
    public:
        Dog() {
            cout << "I am inside dog constructor" << endl;
        }
        void speak() {
            cout << "barking" << endl;
        }
};

int main() {
    cout << endl;

    // Dog d;
    // d.speak();

    //In upcasting and downcasting by default pointer ka method call hoyega and agr object ka method use krna h then us case m VIRTUAL keyword will be used

    // UPCASTING -> Animal ka pointer and Dog ka object
    // Animal* a = new Dog();   
    // a->speak();

    // DownCasting -> Dog ka pointer and Animal ka object
    // Dog* b = (Dog*)new Animal(); // type cast
    // b->speak();



    // Animal* a = new Animal();

    // pehle animal call hoyega and then dog
    // Dog* a = new Dog();
    // Animal* a = new Dog();

    Dog* a = (Dog*)new Animal();

    cout << endl;
    return 0;
}