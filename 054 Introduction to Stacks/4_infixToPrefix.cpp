#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int prec(char ch) {

    if(ch == '^') {
        return 3;
    }
    else if(ch == '*' || ch == '/') {
        return 2;
    }
    else if(ch == '+' || ch == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPrefix(string s) {

    reverse(s.begin(), s.end());
    string ans = "";
    stack<char> st;

    for(int i = 0; i<s.size(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
            ans += s[i];
        }
        else if(s[i] == ')') {
            st.push(s[i]);
        }
        else if(s[i] == '(') {
            while(!st.empty() && st.top() != ')') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else {
            while(!st.empty() && prec(st.top()) > prec(s[i])) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string ans = infixToPrefix("(a-b/c)*(a/k-l)");
    cout << ans;

    return 0;
}