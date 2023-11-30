#include<iostream>
using namespace std;

void calculateSum(int n, int& sum) {
    // base case
    if(n == 0) {
        return;
    }

    sum += n;

    calculateSum(n-1, sum);
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int sum = 0;

    calculateSum(n, sum);

    cout << "sum : " << sum;
    
    return 0;
}