#include<iostream>
using namespace std;

class Animal{
    public:
    void speak() {
        cout << "speaking";
    }
};
// custom implementation in dog class will be called over implementaion in parent class 
class Dog : public Animal {
    public:
    void speak() {
        cout << "barking";
    }
};

int main() {

    Dog d;
    d.speak();

    return 0;
}