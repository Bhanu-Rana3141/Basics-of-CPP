/*
APPROACH 1 - USING EXTRA STACK
TC - O(N) && SC - O(N)

APPROACH 2 - RECURSION
TC - O(N^2) && SC - O(N)

*/

#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> st) {

    while(st.size() != 0) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


// APPROACH 1 - ITERATIVE
stack<int> solve_1(stack<int> st) {

    stack<int> reverseStack;

    while(st.size() != 0) {
        reverseStack.push(st.top());
        st.pop();
    }

    return reverseStack;
}

// APPROACH 2 - RECURSIVE
void insertAtBottom(stack<int>& st, int element) {

    if(st.size() == 0) {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(topElement);
}

void solve_2(stack<int>& st) {

    if(st.size() == 0) {
        return;
    }

    int topElement = st.top();
    st.pop();
    solve_2(st);
    insertAtBottom(st, topElement);
}

int main() {

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Input stack: ";
    print(st);

    // stack<int> reverse = solve_1(st);
    // cout << "output Stack: ";
    // print(reverseStack);

    solve_2(st);
    cout << "Reversed stack: ";
    print(st);
   
    return 0;
}