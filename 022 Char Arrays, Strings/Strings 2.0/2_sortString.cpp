#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string countSort(string s) {

    vector<int> freq(26,0);

    // TC -> O(n) -> where n is length of string, traversing through whole string to calculate freq of each character
    // storing frequency of each character of string  
    for(int i=0; i<s.length(); i++) {
        freq[s[i]-'a']++;
    }

    // sorting
    int j=0;
    for(int i=0; i<26; i++) {
        while(freq[i]--) {
            s[j] = i + 'a';
            j++;
        }
    }
    return s;
} 

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    // sort(s.begin(), s.end());
    // cout << s;

    cout << countSort(s);
    
    return 0;
}