/*Approach 
* Map values of string s with string t using hash table
* After mapping check whether the values of both strings are same
TC : O(n) && SC : O(1)
*/
#include<iostream>
using namespace std;

bool isomorphic(string s, string t) {

    int hash[256] = {0};
    bool isMapped[256] = {0};

    for(int i=0; i<s.size(); i++) {
        if(hash[s[i]] == 0 && isMapped[t[i]] == 0) {
            hash[s[i]] = t[i];
            isMapped[t[i]] = true;
        } 
    }

    for(int i=0; i<s.size(); i++) {
        if(char(hash[s[i]] != t[i])) {
            return false;
        }
    }
    return true;
}

int main() {

    string s;
    cout << "Enter string s: ";
    cin >> s;

    string t;
    cout << "Enter string t: ";
    cin >> t;

    if(isomorphic(s,t)) {
        cout << "strings are isomorphic";
    }
    else{
        cout << "strings are not isomorphic";
    }
    
    return 0;
}