/*

APPROACH 1 - LINEAR SEARCH
* TC - O(N^2)
* SC - O(1)

APPROACH 2 - STACK
* TC - O(N)
* SC - O(N)

*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    
    int n = 3;
    vector<vector<int>> arr(n, vector<int>(n));

    arr[n][n] = {{0, 1, 0}, {0 , 0, 0}, {0, 1, 0}};

    int ans = celebrity_1(arr,n);

    return 0;
}