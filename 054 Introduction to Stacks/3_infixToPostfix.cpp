#include<iostream>
#include<stack>
using namespace std;

/*
1. If alphabet, add in ans string
2. If opening parenthesis, push in stack
3. If closing parenethesis , add operators to ans and pop till '(' is encountered, and then pop ( 
4. If operators add to ans and pop till, operator present at top of stack has more precedence then curr operator and then push curr operator in stack
5. now check condition if stack is not empty add all the characters in ans
*/

int prec(char ch) {
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

string infixToPostfix(string s) {

    string ans = "";
    stack<char> st;

    for(int i = 0; i<s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            ans += s[i];
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) {
                st.pop();
            }
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

    return ans;
}

int main()
{
    string ans = infixToPostfix("(a-b/c)*(a/k-l)");
    cout << ans;
    return 0;
}