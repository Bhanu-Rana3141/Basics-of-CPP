#include<iostream>
using namespace std;

int climbStairs(int n) {

    if(n==0)
        return 1;
    if(n<0)
        return 0;

    return climbStairs(n-1) + climbStairs(n-2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << climbStairs(n);
    return 0;
}