#include<iostream>
using namespace std;

class Hero{
    
    public:
    char level;
    int health; 

    // simple
    Hero() {
        cout << "default constructor" << endl;
    }

    // Parameterised 
    Hero(int health, char level) {
        cout << "this: "<< this << endl;
        this -> health = health;
        this -> level = level;
    }

    // Copy constructor
    Hero(Hero& temp) {
        cout << "copy constructor called "<< endl;
        health = temp.health;
        level = temp.level;
    }

    void print() {
        cout << "Health: " << health << endl;
        cout << "Level: " << level <<endl;
    }
};

int main() {
  
    Hero S(70,'C');   // S.Hero() -> by default
    S.print();

    cout << endl;

    // Copy constructor 
    Hero R(S);      // S.health = R.health , S.level = R.level
    // Hero R = S;
    R.print();

    return 0;
}