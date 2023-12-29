#include<iostream>
using namespace std;

class A{
    private:
        int x;

    public:
        A(int x) {
            this->x = x;
        }

        int getValue() {
            return x;
        }

        friend class B;
        friend void print(A);
};

class B{
    public:
        void print(A& a) {
            cout << a.x << endl;
        }

};

void print(A a) {
    a.x = 10;
    cout << a.x;
}

int main() {

    A a(5);
    cout << a.getValue() << endl;

    B b;
    b.print(a);
    print(a);
    
    return 0;
}