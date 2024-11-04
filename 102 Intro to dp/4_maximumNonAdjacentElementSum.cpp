/*
class Solution{
public:	
	int solveRec(int arr[], int n) {
	    
	    if(n == 0) return arr[0];
	    if(n < 0) return 0;
	    
	    int inc = arr[n] + solveRec(arr, n-2);
	    int exc = 0 + solveRec(arr, n-1);
	    
	    return max(inc, exc);
	}
	
	
	int solveMem(int arr[], int n, vector<int>& dp) {
	    
	    if(n == 0) return arr[0];
	    if(n < 0) return 0;
	    
	    if(dp[n] != -1) return dp[n];
	    
	    int inc = arr[n] + solveMem(arr, n-2, dp);
	    int exc = 0 + solveMem(arr, n-1, dp);
	    
	    return dp[n] = max(inc, exc);
	}
	
	
	int solveTab(int arr[], int n) {
	    
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
	
	
	int solveSpaceOptimisation(int arr[], int n) {
	    
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
	
	
	int findMaxSum(int *arr, int n) {
	   // return solveRec(arr, n-1);
	   
	   //vector<int> dp(n+1, -1);
	   //return solveMem(arr, n-1, dp);
	   
	   //return solveTab(arr, n);
	   
	   return solveSpaceOptimisation(arr, n);
	}
};
*/