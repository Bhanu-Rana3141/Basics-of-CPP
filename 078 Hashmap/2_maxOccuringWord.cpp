#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

    string s = "mera naam hai babbar mera babbar babbar";
    
    unordered_map<string, int> mpp;
    
    int i = 0;
    int j = 0;
    int n = s.size();

    while(j <= n) {

        if(j == n || s[j] == ' ') {
            mpp[s.substr(i, j-i)]++;
            j++;
            i = j;
        }
        else {
            j++;
        }
    }

    string ans = "";
    int cnt = 0;

    for(auto it : mpp) {
        if(it.second > cnt) {
            ans += it.first;
            cnt = it.second;
        }
    }

    cout << ans << " " << cnt;

    return 0;
}