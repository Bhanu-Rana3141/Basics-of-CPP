#include<iostream>
using namespace std;

bool even_or_odd(int n){
    if(n&1){
        return 0;
    }
   return 1;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if(even_or_odd(n) == 1){
        cout << "Even";
    }
    else{
        cout << "Odd";
    }
    return 0;
}