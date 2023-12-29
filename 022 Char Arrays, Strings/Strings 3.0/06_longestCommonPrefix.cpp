#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string>s(n);
    cout << "Enter string arr: ";
    
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    string s1 = s[0];
    string s2 = s[s.size()-1];

    string ans = "";

    int i=0;
    while(i<s1.size() && i<s2.size()) {
        if(s1[i] == s2[i]) {
            ans.push_back(s1[i]);
            i++;
        }
    }
    cout << ans;
    return 0;
}