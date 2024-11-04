/*
#define MOD 1000000007
class Solution {
  public:
    
    // const long int MOD = 1e9 + 7;
    
    long int solveSpaceOptimisation(int n) {
        
        int prev2 = 0;
        int prev1 = 1;
        
        for(int i = 3; i<=n; i++) {
            long int sum = (prev1 + prev2) % MOD;
            long int ans = ((i-1) * sum) % MOD;
            
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }


    long int solveTab(int n) {
    
        vector<long int> dp(n + 1, -1 );
        dp[1] = 0;
        dp[2] = 1;
        
        for (int i = 3; i <= n; i++) {
            long int first = dp[i - 1];
            long int second = dp[i - 2];
            long int sum = (first + second) % MOD;
            
            dp[i] = ((i - 1) * sum) % MOD;
        }
        return dp[n];
    }
    
    
    long int solveMem(int n, vector<long int>& dp) {
        
        if(n == 1) return 0;
        if(n == 2) return 1;

        if(dp[n] != -1) return dp[n];
        
        dp[n] = ((n-1) % MOD) * ( (solveMem(n-1, dp) % MOD) + (solveMem(n-2, dp) % MOD) ) % MOD;
        return dp[n];
    }
    

    long int disarrange(int n) {
        
        // Recursion
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        // int ans = ((n-1) % MOD) * ( (disarrange(n-1) % MOD) + (disarrange(n-2) % MOD) ) % MOD;
        // return ans;
        
        
        // vector<long int> dp(n+1, -1);
        // long int ans = solveMem(n, dp);
        // return ans;
        
       
        // return solveTab(n);
        
        
        return solveSpaceOptimisation(n);
    }
};
*/