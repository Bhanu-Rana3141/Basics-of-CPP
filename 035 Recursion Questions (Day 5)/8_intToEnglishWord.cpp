#include<iostream>
using namespace std;

int main() {

    int num;
    cout << "Enter num: ";
    cin >> num;

    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    string ans = "";
    while(num != 0) {
        int lastDigit = num % 10;
        ans += numbers[lastDigit] + ' ';
        num /= 10;
    }

    cout << ans;

    return 0;
}