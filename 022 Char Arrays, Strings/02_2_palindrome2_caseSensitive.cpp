#include<iostream>
using namespace std;

int getLength(char *str) {
    int count = 0;
    for(int i=0; str[i] != '\0'; i++) {
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

bool isPalindrome(char str[], int size) {
    int s = 0;
    int e = size-1;

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

    int len = getLength(str);
    cout << "size: " << len << endl;

    int ans = isPalindrome(str, len);

    cout << endl << endl;

    if(ans) {
        cout << "palindrome";
    }
    else {
        cout << "not palindrome";
    }

    return 0;
}