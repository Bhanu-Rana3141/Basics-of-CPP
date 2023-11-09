#include<iostream>
#include<limits.h>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int rev = 0;
    while(n > 0) {
        int x = n % 10;
        rev = rev*10+x;
        if((rev > INT_MAX/10) || (rev < INT_MIN)){
            cout << 0;
            exit(0);
        }
        n /= 10;
    }

    cout << "rev: " << rev;
    return 0;
}