/*
APPROACH 1 : ITERATIVE
TC : O(n^3)
SC : O(1)

APPRACH 2 : RECURSIVE
TC : O(n^2)
SC : O(n+2) -> maximum depth of recursive tree
*/

#include<iostream>
#include<vector>
using namespace std;

void printSubarrayIterative(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            for(int k=i; k<=j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

void printSubarraysUtility(vector<int>&arr, int start, int end) {
    if(end == arr.size()) {
        return;
    }
    for(int i=start; i<=end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    printSubarraysUtility(arr, start, end+1);
}

void printSubarray(vector<int>& arr) {
    for(int start=0; start<arr.size(); start++) {
        int end = start;
        printSubarraysUtility(arr, start, end);
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // printSubarrayIterative(arr);

    printSubarray(arr);
    
    return 0;
}