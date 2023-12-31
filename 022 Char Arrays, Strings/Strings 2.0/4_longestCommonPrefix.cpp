/* APPROACH 1
* traversing on each character of string having minimum length b|w first and last i.e TC - O(m) -> where m is the min length b|w first and last string
* sort array of strings- TC : O(n*log(n)) -> where n is the length of string
-> After sorting first and last string will have minimal common prefix which will be present in all other strings 
* Compare characters of first and last string - O(k) -> where k is the size of string
* OVERALL TC -> O(n*log(n) * k) + min(s[0].length, s[s.length()-1])

APPROACH 2: 
* keep 1st string constant and compare all other strings with it
* using 2 loops 1 for traversing through each string of vector, and second one to count the no of common characters between the strings compared currently, then a variable is maintained to store the common prefix, and at last by using substring function ans will be displayed
* TC : O(n*m) -> n is length of vector of strings and m is the length of strings which are compared
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix1(vector<string> &str) {

    // sort the vector - 
    sort(str.begin(), str.end());

    // comparing first and last string
    string s1 = str[0];
    string s2 = str[str.size()-1];

    string ans = "";

    for(int i=0; i<min(s1.size(), s2.size()); i++) {
        if(s1[i] == s2[i]) {
            ans.push_back(s1[i]);
        }
        else{
            break;
        }
    }
    return ans;
}

string longestCommonPrefix2(vector<string> &str) {

    string s1 = str[0]; // keeping first string constant and comparing with other strings
    int ansLength = s1.size();

    for(int i=1; i<str.size(); i++) {
        int j=0;
        while(j < min(s1.size(), str[i].size()) && s1[j] == str[i][j]) {
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

    // cout << "Longest common prefix :" << longestCommonPrefix1(str);

    cout << "Longest common prefix :" << longestCommonPrefix2(str);

    return 0;
}