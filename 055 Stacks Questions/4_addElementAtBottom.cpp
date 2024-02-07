// TC - O(N) && SC - O(N)

#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int>& st) {
    
    while(st.size() != 0) {
        cout << st.top() << " ";
        st.pop();
    }
}

void insertElement(stack<int>& st, int x) {

    if(st.size() == 0) {
        st.push(x);
        return;
    }

    int topElement = st.top();
    st.pop();

    insertElement(st, x);
    
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

    insertElement(st, x);

    printStack(st);
    
    return 0;
}