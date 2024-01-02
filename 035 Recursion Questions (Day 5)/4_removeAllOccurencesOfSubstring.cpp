#include<iostream>
#include<string.h>
using namespace std;

void removeOccurences(string&s, string& part) {
    if(s.find(part) == string::npos) {
        return;
    }
    s.erase(s.find(part), part.length());
    removeOccurences(s, part);
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    string part;
    cout << "Enter part: ";
    cin >> part;

    removeOccurences(s, part);

    cout << s;
    
    return 0;
}