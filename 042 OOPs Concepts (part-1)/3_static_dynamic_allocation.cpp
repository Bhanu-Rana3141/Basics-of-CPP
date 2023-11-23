#include<iostream>
using namespace std;

class Hero{
    
    private:
    int health;
    
    public:
    char level;

    void setHealth(int h){
        this->health = h;
    }

    int getHealth(){
        return health;
    }

    void setLevel(char ch){
        this->level = ch;
    }

    char getLevel(){
        return level;
    }

};

int main() {
    
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
    b->setLevel('B');
    
    // cout << "Health: " << (*b).level << endl;
    // cout << "level: " << (*b).getHealth() << endl;

    cout << "Health: " << b->level << endl;
    cout << "level: " << b->getHealth() << endl;



    

   
    
    return 0;
}