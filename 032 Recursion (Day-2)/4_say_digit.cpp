#include <iostream>
using namespace std;

void sayDigit(int n, string numbers[], string& ans) {

    if(n == 0) {
        return;
    }
    
    int digit = n % 10;
    n /= 10;
    sayDigit(n, numbers, ans);
    ans += numbers[digit] + ' ';
}

void sayDigit(int n, string arr[]) {
    if(n == 0)
        return;

    int digit = n % 10;
    n /= 10;

    sayDigit(n, arr);
    
    cout << arr[digit] << " ";
}

int main() {

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    // sayDigit(n, arr);

    string ans = "";
    sayDigit(n, arr, ans);
    cout << ans;

    return 0;   
}