#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int sum=0, product=1;
    while(n > 0) {
        int x = n%10;
        sum += x;
        product *= x;
        n /= 10;
    }

    cout << "product: " << product << endl;
    cout << "sum : " << sum << endl;
    cout << "difference: " << product-sum;

    return 0;
}