#include<iostream>
using namespace std;

int main() {
    
    int binary;
    cout << "Enter binary no: ";
    cin >> binary;

    int temp = binary;
    int decimal=0, power=1;

    while(binary > 0){
        int x = binary % 10;
        decimal += power*x;
        binary /= 10;
        power *= 2;
    }

    cout << "Decimal of " << temp << ": " << decimal;

    return 0;
}