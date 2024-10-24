#include<iostream>
using namespace std;

int main()
{
    string s1 = "abc";
    string s2 = "xyzfh";

    int n = min(s1.size(), s2.size());
    string ans = "";

    int i = 0;
    while(i < n) {
        ans += s1[i];
        ans += s2[i];
        i++;
    }

    while(i < s1.size()) {
        ans += s1[i];
        i++;
    }

    while(i < s2.size()) {
        ans += s2[i];
        i++;
    }

    cout << "ans: " << ans;

    return 0;
}