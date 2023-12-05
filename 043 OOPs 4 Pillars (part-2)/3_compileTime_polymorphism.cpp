/*
1. FUNCTION OVERLOADING -> same functions performing different tasks, and are differentiated by
* no of parameters
* data type of parameters

2. OPERATOR OVERLOADING ->
*/

#include<iostream>
using namespace std;

class Parameter {
    public:
        int value;

        void operator+(Parameter& object2) {
            int value1 = this->value;
            int value2 = object2.value;

            cout << value2-value1;
        }
};

int main() {

    Parameter object1, object2;

    object1.value = 7;
    object2.value = 3;

    object1 + object2;

    // object 1 -> curr object (address of object 1 is stored in this)
    // +        -> function call, which specifies what operation has to be performed b|w objects
    // object 2 -> passed as an input parameter
    return 0;
}