/*

APPROACH 1 - USE STACK
TC - O(N) && SC - O(N)

APPROACH 2 - RECURSION
TC - O(N) && SC - O(N)

*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void print(queue<int> q) {

    while(q.size() != 0) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverse_1(queue<int>& q) {

    stack<int> st;

    while(q.size() != 0) {
        st.push(q.front());
        q.pop();
    }

    while(st.size() != 0) {
        q.push(st.top());
        st.pop();
    }
}

void reverse_2(queue<int>& q) {
    
    if(q.size() == 0) {
        return;
    }

    int frontElement = q.front();
    q.pop();
    reverse_2(q);
    q.push(frontElement);
}

int main() {

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    print(q);

    // reverse_1(q);
    reverse_2(q);

    print(q);
    
    return 0;
}