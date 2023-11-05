#include<iostream>
using namespace std;

int main() {
    string name;
    cout << "Enter name: ";
    cin >> name;
    cout << name << endl;
    name[2] = '\0';
    cout << name << endl;


    char s[20];
    cout << "Enter : ";
    cin >> s;
    cout << s << endl;
    s[2] = '\0';
    cout << s;
    return 0;
}