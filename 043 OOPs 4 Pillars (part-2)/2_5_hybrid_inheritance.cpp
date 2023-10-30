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

class C: public B {
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
    obj2.func1();
    obj2.func2();

    cout << endl;

    C obj3;
    obj3.func1();
    obj3.func2();
    obj3.func3();
    

    return 0;
}