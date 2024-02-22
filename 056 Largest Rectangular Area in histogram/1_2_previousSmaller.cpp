#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(vector<int> arr, int n) {
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> previousSmaller_1(vector<int>& arr, int n) {

    vector<int> ans(n, -1);

    for(int i=n-1; i>=0; i--) {
        for(int j=i-1; j>=0; j--) {
            if(arr[j] < arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> previousSmaller_2(vector<int>& arr, int n) {

    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i=0; i<n; i++) {

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

    // vector<int> ans = previousSmaller_1(arr, n);
    vector<int> ans = previousSmaller_2(arr, n);

    print(ans, n);
    
    return 0;
}