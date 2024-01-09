#include<iostream>
using namespace std;

void printDigits(int n) {
    if(n == 0) {
        return;
    }
    int digit = n%10;
    n /= 10;

    printDigits(n);
    
    cout << digit << " ";
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    printDigits(n);
    
    return 0;
}