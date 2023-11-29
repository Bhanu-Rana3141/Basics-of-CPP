#include<iostream>
using namespace std;

void removeOccurence(string& s, string part) {
    
    while(s.find(part) != string::npos) {
        s.erase(s.find(part), part.length());
    }
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    string part = "abc";
    removeOccurence(s, part);

    cout << s;
    
    return 0;
}