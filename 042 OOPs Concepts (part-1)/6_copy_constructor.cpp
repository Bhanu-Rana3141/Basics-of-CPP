#include<iostream>
using namespace std;

class Hero{
    
    public:
    char level;
    int health; 

    // simple -> default
    Hero() {
        cout << "default constructor" << endl;
    }

    // Parameterised 
    Hero(int health, char level) {
        cout << "parameterised constructor called" << endl;
        cout << "this: "<< this << endl;
        this -> health = health;
        this -> level = level;
    }

    // Copy constructor
    Hero(Hero& temp){
        cout << "copy constructor called" << endl;
        cout << "temp: " << &temp << endl;
        cout << "this : " << this << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print() {
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
    }
};

int main() {
  
    Hero S(70,'C');   // parameterised constructor
    cout << "address of s: " << &S << endl;
    S.print();

    cout << endl;

    // Copy constructor 
    Hero R(S);      // -> inbuilt copy constructor is called , 
    // Hero R = S; R.health =  S.health, R.level = S.level
    cout << "obj S : " << &S << endl;
    cout << "obj R : " << &R << endl;
    R.print();

    return 0;
}