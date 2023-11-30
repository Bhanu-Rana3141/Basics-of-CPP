#include<iostream>
using namespace std;

bool checkAlphabet(char ch) {
    
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
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
        if(checkAlphabet(s[l]) && checkAlphabet(s[h])) {
            swap(s[l], s[h]);
            l++, h--;
        }
        else if(checkAlphabet(s[l]) == 0) {
            l++;
        }
        else{
            h--;
        }
    }

    cout << s;

/* using inbuilt - isalpha

    int l = 0;
    int h = s.size()-1;

    while(l < h) {
        if(isalpha(s[l]) && isalpha(s[h])) {
            swap(s[l], s[h]);
            l++, h--;
        }
        else if(!isalpha(s[l])) {
            l++;
        }
        else{
            h--;
        }
    }
    cout << s;
*/
    
    
    return 0;
}