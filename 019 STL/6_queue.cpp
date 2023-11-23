// first in first out

#include<iostream>
#include<queue>
using namespace std;

int main() {

    queue<string> s;
    s.push("love");
    s.push("babbar");
    s.push("kumar");

    cout << "front element: " << s.front() << endl;
    s.pop();
    cout << "front element: " << s.front() << endl;

    cout << "size: " << s.size() << endl;
    cout << "check empty? : " << s.empty() << endl;
    
    queue<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "front: " << st.front() << endl;
    cout << "size: " << st.size() << endl;

    cout << endl;
    
/*  PRIORITY QUEUE
    * MAX HEAP -> a queue in which first element will always be the greatest (DEFAULT PQ)
    * when elements will be fetched from queue the greatest element will come out

*/

    cout << "PRIORITY QUEUE" << endl;

    // max heap
    priority_queue<int> maxi;

    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(4);

    int n = maxi.size();
    cout << "max heap: ";
    for(int i=0; i<n; i++) {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    
    cout << endl;

    cout << "maxi khaali h kya : " << maxi.empty() << endl;
    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;
    mini.push(1);
    mini.push(2);
    mini.push(3);
    mini.push(4);
    
    cout << "min heap: ";
    for(int i=0; i<n; i++) {
        cout << mini.top() << " ";
        mini.pop();
    }
    
    cout << endl;

    cout << "mini khali h kya: " << mini.empty() << endl;

    
    

    return 0;
}