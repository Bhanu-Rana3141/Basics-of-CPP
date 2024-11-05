/*
class Solution {
public:

    int solveRec(vector<int>& days, int n, vector<int>& costs, int index) {

        if(index >= n) return 0;

        // 1 day pass
        int option1 = costs[0] + solveRec(days, n, costs, index+1);

        // 7 days pass
        int i;
        for(i = index; i<n && days[i] < days[index] + 7; i++);
        int option2 = costs[1] + solveRec(days, n, costs, i);

        // 30 days pass
        for(i = index; i<n && days[i] < days[index] + 30; i++);
        int option3 = costs[2] + solveRec(days, n, costs, i);

        return min(option1, min(option2, option3));
    } 

    int solveMem(vector<int>& days, int n, vector<int>& costs, int index, vector<int>& dp) {

        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        // 1 day pass
        int option1 = costs[0] + solveMem(days, n, costs, index+1, dp);

        // 7 days pass
        int i;
        for(i = index; i<n && days[i] < days[index] + 7; i++);
        int option2 = costs[1] + solveMem(days, n, costs, i, dp);

        // 30 days pass
        for(i = index; i<n && days[i] < days[index] + 30; i++);
        int option3 = costs[2] + solveMem(days, n, costs, i, dp);

        return dp[index] = min(option1, min(option2, option3));
    } 

    int solveTab(vector<int>& days, int n, vector<int>& costs) {

        vector<int>dp(n+1, INT_MAX);
        dp[n] = 0;

        for(int k = n-1; k >= 0; k--) {
            int option1 = costs[0] + dp[k+1];

            // 7 days pass
            int i;
            for(i = k; i<n && days[i] < days[k] + 7; i++);
            int option2 = costs[1] + dp[i];

            // 30 days pass
            for(i = k; i<n && days[i] < days[k] + 30; i++);
            int option3 = costs[2] + dp[i];

            dp[k] = min(option1, min(option2, option3));
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        // return solveRec(days, n, costs, 0);

        // vector<int> dp(n+1, -1);
        // return solveMem(days, n, costs, 0, dp);

        return solveTab(days, n, costs);
    }
};
*/