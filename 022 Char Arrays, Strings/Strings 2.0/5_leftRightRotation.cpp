#include<iostream>
#include<algorithm>
using namespace std;

void leftRotate(string& s, int k) {

    reverse(s.begin(), s.end());
    reverse(s.begin(), s.end()-k);
}

void rightRotate(string &s2, int k) {

    reverse(s2.begin(), s2.end());
    reverse(s2.begin(), s2.begin()+k);
    reverse(s2.begin()+k, s2.end());
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    int k;
    cout << "Enter k: ";
    cin >> k;

    leftRotate(s, k);
    cout << "Left rotate by " << k << " steps: " << s << endl;

    string s2;
    cout << "Enter string : ";
    cin >> s2;

    rightRotate(s2, k);
    cout << "Right rotate by " << k << " steps " << s2 << endl;

    return 0;
}