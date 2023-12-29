#include<iostream>
using namespace std;

// using reference variable , void return type
void calculateSum(int n, int& sum) {
    // base case
    if(n == 0) {
        return;
    }

    sum += n;

    calculateSum(n-1, sum);
}

// using int return type
int calculateSum(int n) {
    if(n == 1) {
        return 1;
    }
    int sum = n;
    return sum + calculateSum(n-1);
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    // int sum = 0;
    // calculateSum(n, sum);
    // cout << "sum : " << sum;

    int ans = calculateSum(n);
    cout << "Sum : " << ans;

    
    return 0;
}