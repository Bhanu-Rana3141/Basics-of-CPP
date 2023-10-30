#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    
    public:
    char level;
    int health; 
    char *name;

    // simple
    Hero() {
        cout << "default constructor" << endl;
        name = new char[100];
    }

    // Parameterised 
    Hero(int health, char level) {
        cout << "this: "<< this << endl;
        this -> health = health;
        this -> level = level;
    }

    
    Hero(Hero& temp) {
        cout << "copy constructor called "<< endl;
        health = temp.health;
        level = temp.level;
    }

    void print() {
        cout << "Health: " << health << endl;
        cout << "Level: " << level <<endl;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }
};

int main() {
  
    

    return 0;
}