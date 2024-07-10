// TC - O(N^2) && SC - O(N)

#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

vector<int> previousSmaller(vector<int> arr, int n) {

    stack<int> st;
    st.push(-1);
    vector<int> prev(n);

    for(int i=0; i<n; i++) {

        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        prev[i] = st.top();
        st.push(i);
    }
    return prev;
}

vector<int> nextSmaller(vector<int> arr, int n) {

    stack<int> st;
    st.push(-1);
    vector<int>next(n);

    for(int i=n-1; i>=0; i--) {

        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        next[i] = st.top();
        st.push(i);
    }
    return next;
}

int maxArea(vector<int>& arr, int n) {

    int maxArea = INT_MIN;
    vector<int> prev = previousSmaller(arr, n);
    vector<int> next = nextSmaller(arr, n);

    for(int i=0; i<n; i++) {
        
        if(next[i] == -1) {
            next[i] = n;
        }

        int width = next[i] - prev[i] - 1;
        int area = arr[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = maxArea(arr, n);

    cout << "Max Area: " << ans;

    return 0;
}