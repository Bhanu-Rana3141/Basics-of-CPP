#include<iostream>
using namespace std;

string reverse(string s) {
    int start = 0, end = s.length()-1;
    while(start < end) {
        swap(s[start] , s[end]);
        start++, end--;
    }
    return s;
}

int main() {

    string s;
    cout << "Enter string: ";
    getline(cin, s);
    cout << s;

    cout << endl;
    
    string rev = reverse(s);
    cout << rev;

    return 0;
}