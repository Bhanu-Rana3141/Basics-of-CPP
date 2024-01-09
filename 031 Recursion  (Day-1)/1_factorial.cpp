// TC && SC : O(n) 

#include<iostream>
using namespace std;

void factorial(int n, int i, int& fact) {
    if(i > n) {
        return;
    }
    fact *= i;
    factorial(n, i+1, fact);
}

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

    // int ans = factorial(n);
    // cout << ans;

    int fact = 1;
    factorial(n, 1, fact);
    cout << fact;
}