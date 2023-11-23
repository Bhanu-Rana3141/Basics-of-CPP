#include<iostream>
using namespace std;

class Hero{
    // properties
    
    private:
    int health;
    
    public:
    char level;

    void setHealth(int h){
        cout << "this: " << this << endl;
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
    
    Hero ramesh;
    cout << "Address: " << &ramesh << endl;

    // setter    
    ramesh.setHealth(70);
    ramesh.setLevel('A');

    // getter
    cout << "health of ramesh: " << ramesh.getHealth() << endl;
    cout << "Level of ramesh: " << ramesh.getLevel() << endl;

    
    // ramesh.health = 80;
    // ramesh.level = 2;
    // cout<<ramesh.health<<endl;
    // cout<<ramesh.level;
    return 0;
}