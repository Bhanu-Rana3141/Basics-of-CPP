#include<iostream>
#include<cmath>
using namespace std;

int powerr(int base, int power){
    int ans = 1;
    for(int i=1; i<=power; i++){
        ans *= base;
    }
    return ans;
}

int main() {

    int base;
    cout << "Enter base: ";
    cin >> base;

    int power;
    cout << "Enter power: ";
    cin >> power;

    // int ans = powerr(base,power);
    // cout << "Ans: " << ans << endl;
    
    //INBUILT FUNCTION
    double res = pow(base,power);
    cout << "result: " << res;

    return 0;
}