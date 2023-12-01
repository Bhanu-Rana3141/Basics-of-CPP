#include<iostream>
using namespace std;

// parent class
class Human {
    
    protected:
        int age;
        int weight;
        int height;

        void eat() {
            cout << "Eating" << endl;
        }
};

// Male is a Human
class Male : private Human {

    public:
        void print() {
            cout << "inside male class: " << this->age;
        }
};

int main() {

    Male m1;

    m1.print(); // accessing inside Male class
    
    // m1.age(); // accessing outside -> not accessible
    
    return 0;
}