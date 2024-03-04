#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void print(queue<int> q) {

    while(q.size() != 0) {
        cout << q.front() << " ";
        q.pop();
    }
}

// TC - O(N) && SC - O(N)
void reverseKElements(queue<int> &q, int k) {

    stack<int> st;

    for(int i=0; i<k; i++) {
        st.push(q.front());
        q.pop();
    }

    while(st.size() != 0) {
        q.push(st.top());
        st.pop();
    }

    for(int i=0; i<q.size()-k; i++) {
        int value = q.front();
        q.pop();
        q.push(value);
    }
}

int main() {

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    reverseKElements(q, k);

    print(q);
    
    return 0;
}