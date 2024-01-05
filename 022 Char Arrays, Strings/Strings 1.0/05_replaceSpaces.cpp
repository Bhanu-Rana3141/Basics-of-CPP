#include<iostream>
#include<string.h>
using namespace std;

void print(string s) {
    for(int i=0; i<s.size(); i++) {
        cout << s[i];
    }
    cout << endl;
}

int main() {

    string s;
    cout << "Enter string: ";
    getline(cin, s);

/*  using another string    SC-> O(n)

    string temp = "";

    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            // temp.push_back('7');
            // temp.push_back('8');
            // temp.push_back('6');
            // temp += "786"; 
        }
        else{
            temp.push_back(s[i]);
        }
    }

    s = temp;
    print(s);
*/

    // in place replacement    TC -> O(n) : size of string , O(m) : part that has to be replaced , OVERALL : O(m*n),  SC-> O(1)

    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            s.replace(i, 2, "786");
        }
    }
    print(s);

    return 0;
}