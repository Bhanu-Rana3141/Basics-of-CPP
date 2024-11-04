/*
class Solution {
public:

    int solveRec(vector<int>& arr, int n) {

        if(n == 0) return arr[0];
        if(n < 0) return 0;

        int inc = arr[n] + solveRec(arr, n-2);
        int exc = solveRec(arr, n-1);

        return max(inc, exc);
    }

    int solveMem(vector<int>& arr, int n, vector<int>& dp) {

        if(n == 0) return arr[0];
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int inc = arr[n] + solveMem(arr, n-2, dp);
        int exc = solveMem(arr, n-1, dp);

        return dp[n] = max(inc, exc);
    }

    int solveTab(vector<int>& arr, int n) {

        vector<int> dp(n, -1);
        dp[0] = arr[0];

        for(int i = 1; i<n; i++) {
            int inc = arr[i];
            if(i > 1) {
                inc += dp[i-2];
            }
            int exc = dp[i-1];

            dp[i] = max(inc, exc);
        }
        return dp[n-1];
    }

    int solveSpaceOptimisation(vector<int>& arr, int n) {

        int prev2 = 0;
        int prev1 = arr[0];

        for(int i = 1; i<n; i++) {
            int inc = arr[i] + prev2;
            int exc = prev1;
            int ans = max(inc, exc);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> first, second;

        for(int i = 0; i<n; i++) {
            if(i != n-1) {
                first.push_back(nums[i]);
            }
            if(i != 0) {
                second.push_back(nums[i]);
            }
        }

        // return max(solveRec(first, first.size()-1), solveRec(second, second.size()-1));

        // vector<int> dp(n, -1);
        // vector<int> dp2(n, -1);
        // return max(solveMem(first, first.size()-1, dp), solveMem(second, second.size()-1, dp2));

        return max(solveTab(first, first.size()), solveTab(second, second.size()));
    }
};
*/