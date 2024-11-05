/*

class Solution {
public:

    int solveRec(int n) {

        if(n == 0 || n == 1) return 1;
        if(n < 0) return 0;

        return solveRec(n-1) + solveRec(n-2);
    }

    int solveMem(int n, vector<int>& dp) {

        if(n == 0 || n == 1) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp);
    }

    int solveTab(int n) {

        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int spaceOptimisation(int n) {

        int prev2 = 1;
        int prev1 = 1;

        for(int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int climbStairs(int n) {
        
        // return solveRec(n);

        // vector<int> dp(n+1, -1);
        // return solveMem(n, dp);

        // return solveTab(n);

        return spaceOptimisation(n);
    }
};

*/