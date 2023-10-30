#include<iostream>
using namespace std;

class A {
    public:
    void func() {
        cout << "function in A" << endl;
    }
};

class B {
    public:
    void func() {
        cout << "function in B" << endl;
    }
};

class C: public A, public B {
    
};

int main() {

    C obj;
    //obj.func();  -> will return error, functions in A, B are of same name and object in C is not able to figure out from which class it should call function , so for resolving this scope resolution operator is used

    obj.A::func();
    obj.B::func();
    return 0;
}