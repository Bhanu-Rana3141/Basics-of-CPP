#include<iostream>
#include<vector>
using namespace std;

// memoization
int fibo(int n, vector<int>& dp) {

    if(n == 1 || n == 0) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}

// tabulation
int fibo2(int n, vector<int>& dp) {

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// space optimisation
int fibo3(int n) {

    int prev2 = 0;
    int prev1 = 1;

    for(int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {

    int n = 6;

    vector<int> dp(n+1, -1);
    cout << "memoization : " << fibo(n, dp) << endl;
    cout << "tabulation : " << fibo2(n, dp) << endl;
    cout << "space optimisation : " << fibo3(n) << endl;

    return 0;
}