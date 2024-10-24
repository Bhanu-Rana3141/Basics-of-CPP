#include<iostream>
using namespace std;

string gcdOfStrings(string s1, string s2) {

    if(s1 == s2) {
        return s1;
    }
    
    if(s2.size() > s1.size()) {
        return gcdOfStrings(s2, s1);
    }

    if(s1.find(s2) != string::npos) {
        return gcdOfStrings(s1.substr(s2.size()), s2);
    }
    
    return " ";
}

int main()
{
    string s1;
    cout << "Enter s1: ";
    cin >> s1;

    string s2;
    cout << "Enter s2: ";
    cin >> s2;

    string gcd = gcdOfStrings(s1, s2);
    cout << "gcd: " << gcd;

    return 0;
}