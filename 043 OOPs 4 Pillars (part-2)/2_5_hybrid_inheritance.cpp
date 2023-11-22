#include<iostream>
using namespace std;

class A {
    public:
    void func1() {
        cout << "function called in A class" << endl;
    }
};

class B: public A {
    public:
    void func2() {
        cout << "function called in B class" << endl;
    }
};  

class D {
    public:
    void func4() {
        cout << "function called in D class" << endl;
    }
};
class C: public A, public D{
    public:
    void func3() {
        cout << "function called in C class" << endl;
    }
};


int main() {

    A obj1;
    obj1.func1();
    cout << endl;

    B obj2;
    cout << "calling from B : " << endl;
    obj2.func1();
    obj2.func2();
    cout << endl;

    C obj3;
    cout << "calling from C: " << endl;
    obj3.func1();
    obj3.func3();
    obj3.func4();
    cout << endl;

    D obj4;
    cout << "calling from D: " << endl;
    obj4.func4();


    return 0;
}