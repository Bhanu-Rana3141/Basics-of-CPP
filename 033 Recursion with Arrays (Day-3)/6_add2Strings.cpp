/*
TC - O(max(num1, num2) + 1)
SC - O(max(num1, num2) + 1)  
*/

#include<iostream>
#include<algorithm>
using namespace std;

// Due to pass by value, new memory will be created multiple times and stack gets filled and uses more memory which reduces time and space complexity
string add(string num1, int p1, string num2, int p2, int carry) {
    if(p1<0 && p2<0) {
        if(carry != 0) {
            return string(1, carry + '0');
        }
        return "";
    }
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    int sum = n1 + n2 + carry;
    int digit = sum % 10;
    carry = sum/10;
    string ans = "";
    ans.push_back(digit + '0');

    ans += add(num1, p1-1, num2, p2-1, carry);
    return ans;
} 

// Optimised - using pass by reference, a string ans is passed and changes are done in ans string itself no new memory is created which save some time and space
void add(string& num1, int p1, string& num2, int p2, int carry, string& ans) {
    if(p1<0 && p2<0) {
        if(carry != 0) {
            ans.push_back(carry + '0');
        }
        return;
    }
    int n1 = 0;
    if(p1 >= 0) {
        n1 = num1[p1] - '0';
    }
    int n2 = 0;
    if(p2 >= 0) {
        n2 = num2[p2] - '0';
    }
    int sum = n1 + n2 + carry;
    int digit = sum % 10;
    carry = sum/10;
    ans.push_back(digit + '0');
    
    add(num1, p1-1, num2, p2-1, carry, ans);
}
int main() {

    string num1;
    cout << "Enter num1: ";
    cin >> num1;

    string num2;
    cout << "Enter num2: ";
    cin >> num2;

    // string ans = add(num1, num1.size()-1, num2, num2.size()-1, 0);
    string ans = "";
    add(num1, num1.size()-1, num2, num2.size()-1, 0, ans);
    reverse(ans.begin(), ans.end());
    cout << ans;
    
    return 0;
}