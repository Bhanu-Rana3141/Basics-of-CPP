/*
 recursive Fibonacci implementation is not the most efficient one in terms of time and space complexity, as it recalculates the same Fibonacci values multiple times. Memoization or using an iterative approach can significantly improve the performance by avoiding redundant calculations.
 TC - O(2^n)
 SC - O(n)
*/

#include<iostream>
using namespace std;

// Iterative approach
int fibonacci(int n) {

    int a = 0;
    int b = 1;
    int sum = 0;

    for(int i=1; i<=n; i++) {
        a = b;
        b = sum;
        sum = a+b;
        cout << sum << " ";
    }
    cout << endl;
    return sum;
}

// Recursive approach
int fibo(int n) {
    if(n == 0) 
        return 0;
    if(n == 1)
        return 1;
    
    return fibo(n-1) + fibo(n-2);
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Recursive Approach: " << fibo(n) << endl;

    cout << "Iterative Approach : " << fibonacci(n);
     
    return 0;
}