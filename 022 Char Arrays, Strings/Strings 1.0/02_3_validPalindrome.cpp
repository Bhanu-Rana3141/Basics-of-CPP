#include<iostream>
using namespace std;

/* Approach :
1. Remove Invalid -> if valid store in new string
2. convert characters in lowercase
3. check palindrome
*/

bool valid(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return true;
    }
    else{
        return false;
    }
}

char toLowerCase(char ch) {
    // if((ch >= 'a' && ch <= 'z') && (ch <= '0' && ch >= '9')){
    //     return ch;
    // }
    // else{
    //     return ch-'A'+'a';
    // }
    if(ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
} 

bool isPalindrome(string temp) {
    int s = 0;
    int e = temp.length()-1;

    while(s<e) {
        if(temp[s] != temp[e]) {
            return false;
        }
        else {
            s++, e--;
        }
    }
    return true;
}

int main() {
    cout << endl;

    string str;
    cout << "Enter string: ";
    cin >> str;

    // Removing invalid characters
    string temp = "";
    for(int i=0; i<str.length(); i++) {
        if(valid(str[i])) {
            temp.push_back(str[i]);
        }
    }

    // converting in lowercase
    for(int i=0; i<temp.length(); i++) {
        temp[i] = toLowerCase(temp[i]);
    }

    if(isPalindrome(temp)) {
        cout << "Palindrome";
    }
    else{
        cout << "not palindrome";
    }

    return 0;
}