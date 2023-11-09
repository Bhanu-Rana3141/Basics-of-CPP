#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    /*
    1. ~n -> last 3 digits will be the ans, but the starting part has to be eliminated
    2. mask is created to eliminate that part
    
    */

    if(n == 0) {
        cout << "ans: " << 1;
        return 0;
    }

    int m = n;
    int mask = 0;

    while(m != 0) {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }

    int ans = (~n) & mask;
    cout << "ans: " << ans;

    return 0;
}