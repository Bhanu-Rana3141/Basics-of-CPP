#include<iostream>
using namespace std;

char toUpperCase(char ch) {
    
    return ch - 'a' + 'A';
}

void capitalise(string& s) {

    s[0] = toUpperCase(s[0]);
    int i = 1;
    int j = 1;
    int n = s.size();

    while(j < n) {
        if(s[j] == ' ') {
            j = j+1;
            i = j;
            s[i] =  toUpperCase(s[i]);
        }
        j++;
    }
}

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    capitalise(s);
    cout << s;

    return 0;
}