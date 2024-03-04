#include<iostream>
#include<vector>
using namespace std;

// TC - O(N^2) && SC - O(N)
vector<int> firstNegativeNumber(vector<int> arr, int k) {

    vector<int> ans;
    int n = arr.size();

    for(int i=0; i<=n-k; i++) {

        bool isNegative = false;

        for(int j=i; j<i+k; j++) {
            if(arr[j] < 0) {
                ans.push_back(arr[j]);
                isNegative = true;
                break;
            }
        }
        if(isNegative == false) {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {

    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> ans = firstNegativeNumber(arr, k);

    for(auto it : ans) {
        cout << it << " ";
    }
    
    return 0;
}