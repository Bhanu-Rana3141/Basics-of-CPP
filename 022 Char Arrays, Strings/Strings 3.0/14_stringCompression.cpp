#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
    string s = "aabbbccdde";
    string temp = "";
    vector<char> ans;

    int cnt = 1;
    for(int i = 0; i<s.size(); i++) {
        if(s[i] == s[i+1]) {
            cnt++;
        }
        else {
            ans.push_back(s[i]);
            ans.push_back(cnt + '0');
            cnt = 1;
        }
    }

    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}