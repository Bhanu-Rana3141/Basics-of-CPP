/*
APPROACH 1 - USING EXTRA STACK
TC - O(N) && SC - O(N)

APPROACH 2 - RECURSION
TC - O(N) && SC - O(N)
*/

#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int>& st) {
    
    while(st.size() != 0) {
        cout << st.top() << " ";
        st.pop();
    }
}

void insertElement_1(stack<int> &st, int x) {

    stack<int> temp;

    while(st.size() != 0) {
        temp.push(st.top());
        st.pop();
    }

    st.push(x);

    while(temp.size() != 0) {
        st.push(temp.top());
        temp.pop();
    }
}

void insertElement_2(stack<int>& st, int x) {

    if(st.size() == 0) {
        st.push(x);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertElement_2(st, x);
    st.push(topElement);
}

int main() {

    stack<int> st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);

    int x = 100;

    insertElement_1(st, x);
    // insertElement_2(st, x);

    printStack(st);
    
    return 0;
}