#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int>& arr, int target, int& count) {
    if(target == 0) {
        return 0;
    }
    if(target < 0) { 
        return INT_MAX; // INT_MAX is returned because if target value becomes negative, in that case mini should not be updated
    }
    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++) {
        int ans = solve(arr, target-arr[i], count);
        cout << "ans: " << ans << endl;
        if(target - arr[i] == 0) {
            count++;
        }
        if(ans != INT_MAX) {
            mini = min(mini, ans+1);
        }
        cout << "mini: " << mini << endl;
    }
    return mini;
}

int solvee(vector<int>&arr, int target, int output) {
    if(target == output) {
        return 0;
    }
    if(output > target) {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++) {
        int ans = solvee(arr, arr[i] + output, output);
        if(ans != INT_MAX) {
            mini = min(mini, ans+1);
        }
    }
    return mini;
}

int main() {

    int n;
    cout << "Enter size of vector: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int count = 0;

    int ans = solve(arr, target, count);
    // int ans = solvee(arr, target, 0);

    cout << "Minimum no of elements to reach target: " << ans << endl;

    cout << "Total possible ways to make target: " << count;

    return 0;
}