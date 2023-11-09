#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    bool isPrime = true;

    for(int i=2; i<n; i++) {
        if(n%i == 0) {
            isPrime = false;
            break;
        }
    }

    if(n==0 || n==1) {
        cout << "neither prime nor composite";
    }
    else if(isPrime == 1){
        cout << "Prime no";
    }
    else{
        cout << "Not prime";
    }

    return 0;
}