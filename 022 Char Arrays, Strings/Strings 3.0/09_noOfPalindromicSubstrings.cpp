// Calculate Substring : n*(n+1)/2;
/* int totalSubstrings = 0;
    for(int i=0; i<s.size(); i++) {
        totalSubstrings++;
        for(int j=i+1; j<s.size(); j++) {
            totalSubstrings++;
        }
    }
     cout << totalSubstrings;
*/


#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s) {

    int i = 0;
    int j = s.size()-1;
    while(i <= j) {
        if(s[i] != s[j]) {
            return false;
        }
        else{
            i++, j--;
        }
    }
    return true;
}

int main() {

    string s;
    cout << "Enter s: ";
    cin >> s;

    int n = s.size();
    
    vector<string>substrings;

     for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            substrings.push_back(s.substr(i, j-i+1));
        }
    }

    for(int i=0; i<substrings.size(); i++) {
        cout << substrings[i] << endl;
    }

    int count = 0;
    for(int i=0; i<substrings.size(); i++) {
       if(isPalindrome(substrings[i])) {
        count++;
       }
    }   

    cout << "Count: " << count; 

    return 0;
}