//  A stack is a data structure that follows the Last In, First Out (LIFO) principle, where the last element added is the first one to be removed.

#include<iostream>
#include<stack>
using namespace std;

int main() {
    
    stack<int> s;

    s.push(2);
    s.push(3);
    cout << "top element: " << s.top() << endl;

    s.pop();
    cout << "top element: " << s.top() << endl;
   
    if(s.empty()) {
        cout << "stack is empty" << endl;
    }
    else {
        cout << "stack is NOT empty" << endl;
    }

    cout << "size of stack: " << s.size() << endl;


    return 0;
}