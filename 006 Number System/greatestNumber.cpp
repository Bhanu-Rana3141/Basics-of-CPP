#include<iostream>
using namespace std;

int main() {

    int num_1, num_2;
    cout << "Enter no 1 and 2: ";
    cin >> num_1 >> num_2;

    int greater = num_1 > num_2 ? num_1 : num_2;
    cout << "greater in binary: " << greater << endl;

    int decimal = 0;
    int power = 1;

    while(greater > 0){
        int x = greater%10;
        decimal += x*power;
        greater /= 10;
        power *= 2;
    }

    cout << "Decimal no representation of greater no :" << decimal; 

    
    return 0;
}