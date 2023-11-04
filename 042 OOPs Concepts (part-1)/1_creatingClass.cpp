#include<iostream>
using namespace std;

class Hero{
    // properties
    public:
    int health;
};

int main() {

    Hero h1;
    cout<<"Size of h1: " << sizeof(h1) << endl; 
    cout << h1.health;
    return 0;
}