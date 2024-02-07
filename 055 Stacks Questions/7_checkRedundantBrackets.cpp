// TC - O(N) && SC - O(N)

#include<iostream>
#include<stack>
using namespace std;

bool isRedundant(string s) {

    stack<int> st;

    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            st.push(s[i]);
        }
       else {
            // ya toh ')' bracket or lowercase alphabet
            if(s[i] == ')') {
                bool isRedundant = true;
                while(st.top() != '(') {
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true) {
                    return true;
                }
                st.pop();
            }     
        }   
    }
    return false;
}

int main() {

    string s;
    cout << "Enter s: ";
    cin >> s;

    if(isRedundant(s)) {
        cout << "Redundant brackets";
    }
    else {
        cout << "Not redundant";
    }
    
    return 0;
}