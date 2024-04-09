/*
APPROACH
1. create a stack
2. if char is ( [ { push in stack
3. if after first iteration stack is empty and a closed bracket is encountered then the input is invalid parenthesis
4. if closed bracket is encountered and opening parenthesis is present in stack, in that case check for it's corressponding closing parenthesis, if found pop it else return false , invalid parenthesis

TC - O(N) && SC - O(N)
*/

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {

    stack<char> st;

    for(int i=0; i<s.size(); i++) {

        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }
        else {
            // closing bracket
            if(st.size() == 0) {
                return false;
            }
            else {
                if((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
    }
    return st.size() == 0 ? true : false;
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    if(isValid(s)) {
        cout << "valid Parenthesis";
    }
    else {
        cout << "Invalid Parenthesis";
    }
      
    return 0;
}