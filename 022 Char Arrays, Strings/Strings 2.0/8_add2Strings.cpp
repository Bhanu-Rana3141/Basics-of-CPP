#include<iostream>
#include<algorithm>
using namespace std;

string addStrings(string s1, string s2) {
    
    int i = s1.size()-1;
    int j = s2.size()-1;
    int carry = 0;
    int maxi = max(s1.size(), s2.size());
    string ans = "";

    while(maxi != 0) {
        int n1 = 0;
        if(i >= 0) {
            n1 = s1[i] - '0';
        }
        int n2 = 0;
        if(j >= 0) {
            n2 = s2[j] - '0';
        }
        int sum = n1 + n2 + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ans.push_back(digit + '0');
        i--, j--, maxi--;
    }
    if(carry != 0) {
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    string s1;
    cout << "Enter string 1: ";
    cin >> s1;

    string s2; 
    cout << "Enter string 2: ";
    cin >> s2;

    string ans = addStrings(s1, s2);

    cout << "Sum : " << ans;
    
    return 0;
}