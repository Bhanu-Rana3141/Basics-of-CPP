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

    void setHealth(int h){
        health = h;
    }

    int getHealth(){
        return health;
    }

    void setLevel(char ch){
        level = ch;
    }

    char getLevel(){
        return level;
    }

};

int main() {

    cout << "hello" << endl;

    Hero a; // a.Hero()
    cout << "h" << endl;
    cout << endl;
    
    // dynamically
    Hero *h = new Hero; // *h.Hero()

    
    return 0;
}