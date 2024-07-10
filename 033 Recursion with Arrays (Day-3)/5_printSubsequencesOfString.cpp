/*
Include-Exclude Pattern 
Total subsequences - 2^n
*/

#include<iostream>
#include<vector>
using namespace std;

void printSubsequencess(string s, string output, int i, vector<string>& ans) {
    if(i >= s.size()) {
        // cout << output << " ";
        ans.push_back(output);
        return;
    }
    // exclude
    printSubsequencess(s, output, i+1, ans);
    // include
    output += s[i];
    printSubsequencess(s, output, i+1, ans);
}

int main() {

    string s;
    cout << "Enter s: ";
    cin >> s;

    vector<string> ans; // to store ans
    int i = 0;
    string output = ""; // to create ans

    printSubsequencess(s, output, i, ans);

    for(auto it: ans) {
        cout << it << " ";
    }
    
    return 0;
}