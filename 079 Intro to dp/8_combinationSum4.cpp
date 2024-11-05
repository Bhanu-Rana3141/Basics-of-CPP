/*
class Solution {
public:

    int solve(vector<int>& arr, int target) {

        if(target < 0) return 0;
        if(target == 0) return 1;

        int ans = 0;
        for(int i = 0; i<arr.size(); i++) {
            ans += solve(arr, target-arr[i]);
        }
        return ans;
    }

    int solveMem(vector<int>& arr, int target, vector<int>& dp) {

        if(target < 0) return 0;
        if(target == 0) return 1;

        if(dp[target] != -1) return dp[target];

        int ans = 0;
        for(int i = 0; i<arr.size(); i++) {
            ans += solveMem(arr, target-arr[i], dp);
        }
        return dp[target] = ans;
    }

    int solveTab(vector<int>& arr, int target) {

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; i++) {
            for(int j = 0; j < arr.size(); j++) {
                if(i-arr[j] >= 0 ) {
                    dp[i] = min(dp[i], dp[i-arr[j] + 1);
                }
            }
        }

        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        // return solve(nums, target);

        int n = nums.size();
        // vector<int> dp(target+1, -1);
        // return solveMem(nums, target, dp);

        return solveTab(nums, target);
       
    }
};
*/


// PRINT ALL COMBINATIONS EQUAL TO TARGET


/*
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& nums, int n, int target, vector<int> comb, vector<vector<int>>& ans, int& cnt) {

    if(target == 0) {
        ans.push_back(comb);
        cnt++;
        return;
    }
    if(target < 0) return;

    for(int i = 0; i<n; i++) {
        comb.push_back(nums[i]);
        solve(nums, n, target-nums[i], comb, ans, cnt);
        comb.pop_back();
    }    
}

int main() {

    vector<int> nums = {1,2,3};
    int target = 4;

    vector<vector<int>> ans;
    vector<int> comb;

    int cnt = 0;
    solve(nums, nums.size(), target, comb, ans, cnt);

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << "total : " << cnt;
}
*/