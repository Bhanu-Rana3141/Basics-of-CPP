#include<iostream>
using namespace std;

int fibo_loop(int n) {
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

    cout << "using recursion: " << fibo(n) << endl;

    cout << "using loop : ";
    cout << fibo_loop(n);

  
    return 0;
}