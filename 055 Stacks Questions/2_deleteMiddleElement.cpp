// TC - O(N) && SC - O(N)

#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> st) {

    while(st.size() != 0) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void deleteMiddle_1(stack<int> &st, int size) {

    int mid = size / 2;
    stack<int> temp;
    
    for(int i=0; i<mid; i++) {
        temp.push(st.top());
        st.pop();
    }

    st.pop(); // middle element

    while(temp.size() != 0) {
        st.push(temp.top());
        temp.pop();
    }
}

void deleteMiddle_2(stack<int>& st, int count, int size) {

    if(count == size/2) {
        st.pop();
        return;
    }

    int topElement = st.top();

    st.pop();

    deleteMiddle_2(st, count + 1, size);

    st.push(topElement);
}

int main() {

    stack<int> st;
    int n = 5;

    cout << "Enter elements in stack: ";
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        st.push(input);
    }

    printStack(st);

    int count = 0;
    // deleteMiddle_1(st, n);
    deleteMiddle_2(st, count, n);

    printStack(st); 
    
    return 0;
}