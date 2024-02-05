// TC - O(N) && SC - O(N)

#include<iostream>
#include<stack>
using namespace std;

int main() {

    string str = "hello";

    stack<char> s;

    for(int i=0; i<str.length(); i++) {
        s.push(str[i]);
    }

    string ans = "";
    
    while(s.size() != 0) {
        ans.push_back(s.top());
        s.pop();
    }

    cout << "ans: " << ans;
    
    return 0;
}