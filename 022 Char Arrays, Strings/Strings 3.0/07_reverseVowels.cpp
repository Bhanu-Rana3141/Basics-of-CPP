#include<iostream>
using namespace std;

bool isVowel(char ch) {
    if((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') || (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
        return true;
    }
    else{
        return false;
    }
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    int l = 0;
    int h = s.size()-1;

    while(l < h) {
        if(isVowel(s[l]) && isVowel(s[h])) {
            swap(s[l], s[h]);
            l++, h--;
        }
        else if(isVowel(s[l]) == 0) {
            l++;
        }
        else{
            h--;
        }
    }

    cout << s;
    
    
    return 0;
}