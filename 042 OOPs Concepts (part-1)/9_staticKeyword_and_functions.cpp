#include<iostream>
using namespace std;

class Hero{
    
    public:
    int health;
    char level;
    static int timeToComplete;

    static int random() {
        return timeToComplete;
    }

};

int Hero :: timeToComplete = 5;

int main() {
/*
    cout << Hero::timeToComplete << endl;
   
    Hero a;
    cout << a.timeToComplete << endl;
    a.timeToComplete = 10;
    cout << Hero::timeToComplete << endl;
    cout << a.timeToComplete << endl;

    Hero::timeToComplete = 20;
    cout << Hero:: timeToComplete << endl;
*/

    //static function
    cout << Hero::random() ;

    
    return 0;
}