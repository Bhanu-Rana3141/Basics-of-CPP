#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    if(n&1) {
        cout << "odd";
    }
    else{
        cout << "Even";
    }

    return 0;
}