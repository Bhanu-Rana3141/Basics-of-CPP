/*
APPROACH 1 - USE ARRAY
* Create a array and copy all stack elements in it - O(N)
* Sort array 
* Create a another stack and copy values from the sorted array

* TC - O(N) + O(N * LOG N) + O(N) : O(N * LOG N)
* SC - O(N) - array, O(N) - stack, : O(2N)


APPROACH 2 - RECURSION
* TC - O(N^2)
* SC - O(N)
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

void sortedInsert(stack<int>& st, int element) {

    if(st.size() == 0 || st.top() < element) {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(topElement);
}

void sortedStack(stack<int>& st) {

    if(st.size() == 0) {
        return;
    }

    int topElement = st.top();
    st.pop();
    sortedStack(st);
    sortedInsert(st, topElement);
}

int main() {

    stack<int> st;

    st.push(5);
    st.push(2);
    st.push(4);
    st.push(7);
    st.push(10);

    cout << "Input stack: ";
    print(st);

    sortedStack(st);

    cout << "Sorted stack: ";
    print(st);

    
    return 0;
}