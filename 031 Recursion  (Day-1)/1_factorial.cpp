#include<iostream>
using namespace std;

int factorial(int n){
    // Base Case
    if(n == 0)
        return 1;
    
    // Recursive relation   
    return n*factorial(n-1);
}

int main() {
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans = factorial(n);
    cout << ans;
}