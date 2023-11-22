#include<iostream>
using namespace std;

// parent class
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

class Male : protected Human{

    public:
    string color;

    void setWeight(int w) {
        this->weight = w;
    }

    int getWeight() {
        return this->weight;
    }
    
    void sleep() {
        cout << "male sleeping" << endl;
    }

};

int main() {
     
    Male m1;
    cout << m1.getWeight() << endl;

    // cout << object1.age << endl;
    // cout << object1.height << endl;
    // cout << object1.weight << endl;
    // cout << object1.color;
    
    // object1.setWeight(64);
    // cout << object1.weight << endl;

    // object1.sleep();


    return 0;
}