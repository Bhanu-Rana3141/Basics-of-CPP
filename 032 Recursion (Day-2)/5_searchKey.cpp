#include<iostream>
#include<vector>
using namespace std;

void searchKey(string& s, char& key, int i, vector<int>& ans, int& count) {
    // base case
    if(i >= s.length()) {
       return;
    }

    // 1 case
    if(s[i] == key) {
        ans.push_back(i); // storing index of all occurences
        count++; // counting occurence
    }
    
    // baaki recursion sambhal lega
    searchKey(s, key, i+1, ans, count);
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    char key;
    cout << "Enter key: ";
    cin >> key;

    vector<int>ans;
    int count = 0;
    int i = 0;

    searchKey(s, key, i, ans, count);

    cout << "Key present at indexes: ";
    for(auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    cout << "count: " << count << endl;

    
    return 0;
}