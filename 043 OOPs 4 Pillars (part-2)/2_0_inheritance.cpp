#include<iostream>
using namespace std;

class Human {
    public:
    int age;
    int weight;
    int height;

    public:
    int getAge() {
        return age;
    }

    void setWeight(int w){
        this->weight = w;
    }
};

class Male: public Human{

    public:
    string color;

    void setWeight(int w) {
        this->weight = w;
    }

    void sleep() {
        cout << "male sleeping" << endl;
    }

};

int main() {
     
    Male object1;
    cout << object1.age << endl;
    cout << object1.height << endl;
    cout << object1.weight << endl;
    cout << object1.color;
    
    object1.setWeight(64);
    cout << object1.weight << endl;

    object1.sleep();

    return 0;
}