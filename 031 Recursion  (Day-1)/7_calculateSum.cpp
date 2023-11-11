#include<iostream>
using namespace std;

int calculateSum(int n, int sum) {

    // base case
    if(n == 0) {
        return sum;
    }

    // processing
    sum += n;

    // recursive relation
    calculateSum(n-1,sum);
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int sum = 0;
    cout << "sum: " << calculateSum(n,sum);

    return 0;
}