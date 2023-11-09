#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int a = 0;
    int b = 1;
    int sum = 0;

    for(int i=1; i<=n; i++) {
        sum = a+b;
        cout << sum << " ";
        a = b;
        b = sum;
    }
    
    cout << endl;

    cout << sum;

    return 0;
}