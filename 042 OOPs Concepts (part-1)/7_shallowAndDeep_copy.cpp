/* SHALLOW COPY 
accessing same address with different names -> pass by reference 
(DEFAULT COPY CONSTRUCTOR DO SHALLOW COPY)

DEEP COPY -> copies are created, different memory is allocated
EXPLICITLY CREATED CONSTRUCTOR DO DEEP COPY
*/
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
        cout << "default constructor called" << endl;
        name = new char[100];
    }

    Hero(char name[], int health, char level) {
        this->name = name;
        this->health = health;
        this->level = level;
    }
    // void setHealth(int health) {
    //     this->health = health;
    // }

    // void setLevel(char level) {
    //     this->level = level;
    // }

    // void setName(char name[]) {
    //     strcpy(this->name, name);
    // }

    Hero(Hero &temp) {
        cout << "copy constructor called " << endl;
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level; 
    }

    void print() {
        cout << "name: " << name << ", ";
        cout << "Health: " << health << ", ";
        cout << "Level: " << level << endl;
        cout << endl;
    }
};

int main() {
  
    Hero hero1; // simple constructor called

    char name[7] = "Babbar";
    hero1.name = name;
    hero1.health = 70;
    hero1.level = 'A';

    // hero1.setHealth(70);
    // hero1.setLevel('D');
    // char name[7] = "Babbar";
    // hero1.setName(name);

    hero1.print();

    //use default copy constructor
    Hero hero2(hero1);  // Hero hero2 = hero1
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();
    
    return 0;
}