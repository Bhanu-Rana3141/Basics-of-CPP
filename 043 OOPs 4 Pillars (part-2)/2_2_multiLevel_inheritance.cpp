#include<iostream>
using namespace std;

// parent class
class Animal {

    public:
    int age;
    int weight;

    public:
    void speak() {
        cout << "speaking" << endl;
    }
};

// child class
class Dog: public Animal {

};

class Germanshephard: public Dog {

};

int main() {

    Germanshephard g;
    g.speak();
    cout << g.age << endl;
    cout << g.weight << endl;
    

    return 0;
}