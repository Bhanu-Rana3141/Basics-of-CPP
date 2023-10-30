/*
public
private -> by default
protected
*/

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
    Hero ramesh;

    cout<<"Health : "<<ramesh.getHealth()<<endl;
    cout<<"level: "<<ramesh.getLevel()<<endl;

    // setter    
    ramesh.setHealth(70);
    ramesh.setLevel('A');

    // getter
    cout<<"health of ramesh: "<<ramesh.getHealth()<<endl;
    cout<<"Level of ramesh: "<<ramesh.getLevel()<<endl;

    
    // ramesh.health = 80;
    // ramesh.level = 2;
    // cout<<ramesh.health<<endl;
    // cout<<ramesh.level;
    return 0;
}