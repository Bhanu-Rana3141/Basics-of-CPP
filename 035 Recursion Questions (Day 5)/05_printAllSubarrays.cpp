/*
TC : O(n^2)
SC : O(n+2) -> maximum depth of recursive tree
*/

#include<iostream>
#include<vector>
using namespace std;

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

    printSubarray(arr);
    
    return 0;
}