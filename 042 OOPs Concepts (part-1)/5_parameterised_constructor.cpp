#include<iostream>
using namespace std;

class Hero{
    
    public:
    char level;
    int health; 

    Hero(int health, char level) {
        cout << "this: "<< this << endl;
        this -> health = health;
        this -> level = level;
    }
};

int main() {
  
    // Hero suresh; 
    // if constructor is made explicitly then, the default constructor will be vanished
 
   // static
    Hero ramesh(70, 'A');
    cout << "Address of obj: " << &ramesh << endl;
    cout << "Health: " << ramesh.health << endl;
    cout << "Level: " << ramesh.level <<endl;
    
    cout << endl;

    // dynamic
    Hero *h = new Hero(100, 'B');
    cout << "Address of obj: " << h << endl;
    cout << "health: " << h -> health << endl;
    cout << "level: " << h -> level << endl;

    return 0;
}