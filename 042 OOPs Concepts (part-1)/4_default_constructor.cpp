#include<iostream>
using namespace std;

class Hero{
    // properties
    
    private:
    int health;
    
    public:
    char level;

    Hero() {
        cout << "Constructor called" << endl;
    }

    // setting health
    void setHealth(int h){
        health = h;
    }

    int getHealth(){
        return health;
    }

    // setting level
    void setLevel(char ch){
        level = ch;
    }

    char getLevel(){
        return level;
    }

};

int main() {
    // creation of object of class Hero

    // static memory allocation
    cout << "hello" << endl;

    Hero a; // a.Hero()

    cout << "h" << endl;
    
    cout << endl;
    // dynamically
    Hero *h = new Hero; // *h.Hero()

    
    return 0;
}