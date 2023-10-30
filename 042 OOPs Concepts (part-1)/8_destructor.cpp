#include<iostream>
using namespace std;

class Hero{
    // properties
    
    private:
    int health;
    
    public:
    char level;

    // constructor
    Hero() {
        cout << "Constructor called" << endl;
    }

    ~Hero() {
        cout << "destructor called" << endl;
    }

};

int main() {
   
    // static -> destructor called automatically
    Hero a;

    // dynamic -> destructor will be called manually
    Hero *b = new Hero();
    delete b;

    
    return 0;
}