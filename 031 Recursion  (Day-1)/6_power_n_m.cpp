#include<iostream>
using namespace std;

// void calculatePower(int base, int power, int& ans, int i) {
//     // base case
//     if(i > power) {
//         return;
//     }
//     // 1 case sove karo
//     ans = ans * base;

//     // baaki recursion sambhal lega
//     calculatePower(base, power, ans, i+1);
// }

void calculatePower(int base, int power, int& ans){
    // base case
    if(power == 0) {
        return;
    }

    ans = ans * base;

    cout <<"ans for " << power << " is : " << ans << endl;
    calculatePower(base, power-1, ans);
}

int main() {

    int base;
    cout << "Enter base: ";
    cin >>base;

    int power;
    cout << "Enter power: ";
    cin >> power;

    int ans = 1;

    // calculatePower(base, power, ans, 1);

    calculatePower(base, power, ans);

    cout << "ans: " << ans;
   
    return 0;
}