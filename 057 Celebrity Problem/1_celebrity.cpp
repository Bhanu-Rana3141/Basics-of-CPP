/*

APPROACH 1 - LINEAR SEARCH
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

int celebrity_1(vector<vector<int>> arr, int n) {

    for(int i=0; i<n; i++) {

        bool isCelebrity = true;

        // check row
        for(int col=0; col<n; col++) {
            if(arr[i][col] == 1) {
                isCelebrity = false;
                break;
            }
        }
        
        // check col
        for(int row=0; row<n; row++) {
            if(i == row) {
                continue;
            }
            if(arr[row][i] != 1) {
                isCelebrity = false;
                break;
            }
        }        
        if(isCelebrity == true) {
            return i;
        }
    }
    return -1;
}

int celebrity_2(vector<vector<int>> arr, int n) {

    stack<int> st;

    // STEP 1 : push all elements(rows) in stack
    for(int i=0; i<n; i++) {
        st.push(i);
    }

    // STEP 2 : get 2 elements and compare them
    while(st.size() > 1) {
        int num1 = st.top();
        st.pop();

        int num2 = st.top();
        st.pop();

        if(arr[num1][num2] == 1) {
            st.push(num2);
        }
        else {
            st.push(num1);
        }
    }

    // STEP 3: single element in stack, but not sure whether celebrity or not, so verify it by checking row and col
    int ans = st.top();

    // check row
    for(int col=0; col<n; col++) {
        if(arr[ans][col] == 1) {
           return -1;
        }
    }

    // check col 
    for(int row=0; row<n; row++) {
        if(row == ans) {
            continue;
        }
        if(arr[row][ans] == 0) {
            return -1;
        }
    }
    return ans;
}

int main() {
    
    int n = 3;

    // Q. why we need to initialise col ?
    vector<vector<int>> arr{{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    // int ans = celebrity_1(arr, n);
    
    int ans = celebrity_2(arr, n);
    
    cout << "Celebrity : " << ans;

    return 0;
}