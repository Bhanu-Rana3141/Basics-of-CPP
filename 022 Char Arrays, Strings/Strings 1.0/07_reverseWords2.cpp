/*
TC -> O(n) - size of string, O(m) - a word that is reversed , OVERALL - O(n*m)
SC - O(1) - Inplace reversal
*/

#include<iostream>
#include<algorithm>
using namespace std;

void reverse(string& s, int start, int end) {
    while(start <= end) {
        swap(s[start], s[end]);
        start++, end--;
    }
}

int main() {

    string s;
    cout << "Enter s: " ;
    getline(cin, s);

    reverse(s.begin(), s.end());

    int i=0, j=0;
    while(j<s.size()) {
        if(s[j] == ' ') {
            reverse(s, i, j-1);
            j++;
            i=j;
        }
        else if(s[j+1] == '\0') { // (j == s.size()-1)
            reverse(s, i, j);
            break;
        }
        else{
            j++;
        }
    }
    
    cout << s;

    return 0;
}