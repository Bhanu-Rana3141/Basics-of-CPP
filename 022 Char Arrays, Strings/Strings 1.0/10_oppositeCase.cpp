#include<iostream>
using namespace std;

void convertOpposite(string& s) {

    for(int i = 0; i < s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z')) {
            s[i] = s[i] - 'a' + 'A';
        }
        else {
            s[i] = s[i] - 'A' + 'a';
        }
    }
} 

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    convertOpposite(s);
    
    cout << s;

    return 0;
}