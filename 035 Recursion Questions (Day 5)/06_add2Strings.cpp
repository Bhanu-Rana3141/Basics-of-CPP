#include<iostream>
#include<algorithm>
using namespace std;

void addStrings(string& s1, int p1, string& s2, int p2, int carry, string& ans) {
    if(p1<0 && p2<0) {
        if(carry != 0) {
            ans.push_back(carry + '0');
        }
        return;
    }
    int n1 = 0;
    if(p1 >= 0) {
        n1 = s1[p1] - '0';
    }
    int n2 = 0;
    if(p2 >= 0) {
        n2 = s2[p2] - '0';
    }
    int sum = n1 + n2 + carry;
    carry = sum / 10;
    int digit = sum % 10;
    ans.push_back(digit + '0');

    addStrings(s1, p1-1, s2, p2-1, carry, ans);
}

int main() {

    string s1;
    cout << "Enter string 1: ";
    cin >> s1;

    string s2;
    cout << "Enter string 2: ";
    cin >> s2;

    int p1 = s1.size()-1;
    int p2 = s2.size()-1;
    int carry = 0;
    string ans = "";

    addStrings(s1, p1, s2, p2, carry, ans);
    reverse(ans.begin(), ans.end());

    cout << "Sum : " << ans;
    
    return 0;
}