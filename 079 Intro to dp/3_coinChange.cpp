/*
class Solution {
public:

    int solveRec(vector<int>& coins, int target) {

        if(target == 0) return 0;
        if(target < 0) return INT_MAX;

        int mini = INT_MAX;
        for(int i = 0; i<coins.size(); i++) {
            int ans = solveRec(coins, target - coins[i]);
            if(ans != INT_MAX) {
                mini = min(mini, ans + 1);
            }
        }
        return mini;
    }

    int solveMem(vector<int>& coins, int target, vector<int>& dp) {

        if(target == 0) return 0;
        if(target < 0) return INT_MAX;

        if(dp[target] != -1) return dp[target];

        int mini = INT_MAX;
        for(int i = 0; i<coins.size(); i++) {
            int ans = solveMem(coins, target-coins[i], dp);
            if(ans != INT_MAX) {
                mini = min(mini, ans+1);
            }
        }

        return dp[target] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        if(amount == 0) return 0;
        if(n == 1 && amount < coins[0]) return -1;

        // int ans = solveRec(coins, amount);

        vector<int> dp(amount+1, -1);
        int ans = solveMem(coins, amount, dp);

        if(ans != INT_MAX) return ans;
        return -1;
        
    }
};
*/