#include<iostream>
using namespace std;

class B {
    public:
    int a;
    int b;

    public:
    // function operloading
    void operator+ (B &obj) {
        cout << "output:" << obj.a - this->a << endl;
    }

    void operator() () {
        cout << "function called for bracket " << this->a << endl;
    }
};  

int main() {
    B obj1, obj2;

    obj1.a = 4; 
    obj2.a = 7;

    obj1 + obj2;

    obj1();

    return 0;
}