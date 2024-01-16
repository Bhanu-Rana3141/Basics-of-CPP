#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void maximumSum(vector<int>& arr, int i, int sum, int& maxSum) {
    if(i >= arr.size()) {
        maxSum = max(maxSum, sum);
        return;
    }

    maximumSum(arr, i+1, sum, maxSum);
    sum += arr[i];
    maximumSum(arr, i+2, sum, maxSum);
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    } 

    int sum = 0; // need to calculate max sum
    int maxSum = INT_MIN;
    int index = 0;

    maximumSum(arr, index, sum, maxSum);

    cout << "maximum sum : " << maxSum;

    return 0;
}