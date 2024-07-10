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
    vector<int> next(n);

    for(int i=n-1; i>=0; i--) {

        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        } 

        next[i] = st.top();
        st.push(i);
    }
    return next;
}

int largestArea(vector<int> arr, int n) {

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

    int n = 4;
    int m = 4;

    vector<vector<int>> arr = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    int maxArea = largestArea(arr[0], m);

    for(int i=1; i<n; i++) {

        for(int j=0; j<m; j++) {
            if(arr[i][j] != 0) {
                arr[i][j] = arr[i][j] + arr[i-1][j];
            }
        }        

        int area = largestArea(arr[i], m);
        maxArea = max(maxArea, area);
    }

    cout << "max area: " << maxArea;

    return 0;
}