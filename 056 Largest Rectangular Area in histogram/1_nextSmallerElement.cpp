/*
APPROACH 1 - nested loops
* TC - O(N^2)
* SC - O(1)

APPROACH 2 - STACK
* TC - O(N)
* SC - O(N)
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(vector<int> arr) {

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> nextSmaller1(vector<int>& arr, int n) {

    vector<int> ans;
    
    for(int i=0; i<n; i++) {
        bool smaller = false;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[i]) {
                ans.push_back(arr[j]);
                smaller = true;
                break;
            }
        }
        if(smaller == false) {
            ans.push_back(-1);
        }
    }
    return ans;
}

vector<int> nextSmaller2(vector<int> arr, int n) {

    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {

        while(st.top() >= arr[i]) {
            st.pop();
        }

        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // vector<int> ans = nextSmaller1(arr, n);
    vector<int> ans = nextSmaller2(arr, n);

    print(ans);

    return 0;
}