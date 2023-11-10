// last in first out 
// first in last out

#include<iostream>
#include<stack>
using namespace std;

int main() {

    stack<string> s;
    s.push("love");
    s.push("babbar");
    s.push("kumar");

    cout << "top element: " << s.top() << endl;
    cout << "size: " << s.size() << endl;
    cout << "check empty? : " << s.empty() << endl;

    int size = s.size();
    for(int i=0; i<size; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl << endl;


    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "top: " << st.top() << endl;
    cout << "size: " << st.size() << endl;

    int n = st.size();
    for(int i=0; i<n; i++) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}