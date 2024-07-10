/*APPROACH
* create a array of roman values
* create another array of numeric values mapped with roman values 
*/
#include<iostream>
using namespace std;

int main() {

    int num;
    cout << "Enter num: ";
    cin >> num;

    string romanValues[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int numericValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans = "";
    for(int i = 0; i<13; i++) {
        while(num >= numericValues[i]) {
            ans += romanValues[i];
            num = num - numericValues[i];
        }
    }

    cout << "Ans: " << ans;
     
    return 0;
}