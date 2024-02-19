/*
CASE 1 -> no removal, already palindrome
CASE 2 -> 1 removal either i or j 
CASE 3 -> more than 1 removal -> not palindrome


TC : O(n) + O(n) = O(2n) -> O(n)
checkPalindrome -> O(n)
isPalindrome -> O(n)
*/

#include<iostream>
using namespace std;

bool checkPalindrome(string s, int i, int j) {
    
    while(i <= j) {
        if(s[i] != s[j]) {
            return false;
        }
        else{
            i++, j--;
        }
    }
    return true;
}

bool isPalindrome(string s) {

    int i = 0;
    int j = s.length()-1;

    while(i <= j) {
        if(s[i] == s[j]) {
            // no removal
            i++, j--;
        }
        else{
            // 1 removal either i or j
            return checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1);
        }
    }
    return true;
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    if(isPalindrome(s)) {
        cout << "String is palindrome";
    }
    else{
        cout << "String is not palindrome";
    }
    
    return 0;
}