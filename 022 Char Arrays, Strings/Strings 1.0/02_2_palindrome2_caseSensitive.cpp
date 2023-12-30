#include<iostream>
#include <string.h>
using namespace std;

int getLength(char ch[]) {
    int count = 0;
    for(int i=0; ch[i] != '\0'; i++) {
        count++;
    }
    return count;
}

char toLowerCase(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        return ch;
    }
    else{
        return ch-'A'+'a';
    }
} 

char toUpperCase(char ch) {
    if(ch >= 'A' && ch <= 'Z') {
        return ch;
    } 
    else{
        return ch-'a'+'A';
    }
}

bool isPalindrome(char str[]) {
    int s = 0;
    int e = getLength(str)-1;

    while(s<e) {
        if(toLowerCase(str[s]) != toLowerCase(str[e])) {
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

    cout << "Enter string: ";
    char str[10];
    cin >> str;

    int ans = isPalindrome(str);

    if(ans) {
        cout << "palindrome";
    }
    else {
        cout << "not palindrome";
    }

    return 0;
}