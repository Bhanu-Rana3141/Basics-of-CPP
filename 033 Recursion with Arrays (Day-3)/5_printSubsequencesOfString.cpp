/*
Include-Exclude Pattern 
Total subsequences - 2^n
*/

#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(string s, string output, int i, vector<string>& ans) {
    if(i == s.size()) {
        cout << output << " ";
        // ans.push_back(output);
        return;
    }
    // exclude

    // include
    output.push_back(s[i]);
    printSubsequences(s, output, i+1, ans);
    output.pop_back();
    printSubsequences(s, output, i+1, ans);

}

int main() {

    string s;
    cout << "Enter s: ";
    cin >> s;

    vector<string> ans;

    int i=0;
    string output = "";
    printSubsequences(s, output, i, ans);

    // for(auto it: ans) {
    //     cout << it << " ";
    // }
    
    return 0;
}