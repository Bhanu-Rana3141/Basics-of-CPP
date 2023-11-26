/* TC -> O(n*m * log n)) + O(m) 
SC -> O(m) , ans string

Approach 1 
* sort the vector of strings 
TC -> O(n*m * log n)) -> where n is no of strings in vector and m is length of each string, and log(n) for sorting

* compare first and last string of vector because the no of same characters in first and last string will be present in all the strings between first and last, therefore if any character is not same then it will not be present in any of the string, if the characters of strings are equal store it in ans string
TC -> O(m)

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string commonPrefix(vector<string> &str) {

    // sort the array
    sort(str.begin(), str.end());

    // comparing first and last string
    string s1 = str[0];
    string s2 = str[str.size()-1];

    string ans = "";

    int i=0, j=0;
    while(i<s1.size() && j<s2.size()) {
        // while comparing strings, each character get's compared and due to which tc is O(m) where m is length of string, and in case of integer only 1 comparison is done TC->O(1)
        if(s1[i] == s2[i]) {
            ans.push_back(s1[i]);
            i++, j++;
        }
        else{
            break;
        }
    }
    return ans;
}

string longestCommonPrefix(vector<string> &str) {

    string s1 = str[0]; // keeping first string constant and comparing with other strings
    int ansLength = s1.size();

    for(int i=1; i<str.size(); i++) {
        int j=0;
        while(j<s1.size() && j<str[i].size() && s1[j]==str[i][j]) {
            j++;
        }
        ansLength = min(ansLength, j);
    }
    string ans = s1.substr(0, ansLength);
    return ans;
}

int main() {

    int n;
    cout << "Enter no of strings: ";
    cin >> n;

    vector<string> str(n);

    for(int i=0; i<n; i++) {
        cin >> str[i];
    }

    // cout << "Longest common prefix :" << commonPrefix(str);

    cout << "Longest common prefix :" << longestCommonPrefix(str);

    
    
    return 0;
}