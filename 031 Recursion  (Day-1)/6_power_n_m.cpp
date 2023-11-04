#include<iostream>
using namespace std;

int main() {

    int base;
    cout << "Enter n: ";
    cin >> base;

    int power;
    cout << "Enter m: ";
    cin >> power;

    int ans = 1;
    
    for(int i=1; i<=power; i++) {
        ans = ans*base;
    }

    cout << base << " raised to power " << power << " : " << ans;



    return 0;
}