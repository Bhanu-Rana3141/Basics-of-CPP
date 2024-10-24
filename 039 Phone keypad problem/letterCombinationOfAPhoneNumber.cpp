#include<iostream>
#include<vector>
using namespace std;

void solve(string digits, vector<string>& ans, string output, int index, vector<string>& mapping) {
    if(index >= digits.size()) {
        ans.push_back(output);
        return;
    }
    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i=0; i<value.size(); i++) {
        // output.push_back(value[i]);
        solve(digits, ans, output + value[i], index+1, mapping);
        // output.pop_back();
    }
}

int main() {

    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    // EDGE CASE - if input string does not have any value
    if(digits.size() == 0) {
        cout << "No combinations possible";
        return 0;
    }

    vector<string>ans;
    string output = "";
    int index = 0;

    vector<string>mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, ans, output, index, mapping); 
    
    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}