#include<iostream>
using namespace std;

class Hero{
    // properties
    
    private:
    int health;
    
    public:
    char level;

    // setting health
    void setHealth(int h){
        this->health = h;
    }

    int getHealth(){
        return health;
    }

    // setting level
    void setLevel(char ch){
        this->level = ch;
    }

    char getLevel(){
        return level;
    }

};

int main() {
    // creation of object of class Hero

    // static memory allocation
    Hero a;
    a.setHealth(70);
    a.setLevel('A');
    cout << "Health: " << a.level << endl;
    cout << "level: " << a.getHealth() << endl;

    cout << endl;

    // dynamically
    Hero *b = new Hero;
    (*b).setHealth(80);
    b -> setLevel('B');
    
    // cout << "Health: " << (*b).level << endl;
    // cout << "level: " << (*b).getHealth() << endl;

    cout << "Health: " << b -> level << endl;
    cout << "level: " << b -> getHealth() << endl;



    

   
    
    return 0;
}