#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Approach 1 -> frequency
// Approach 2 -> sort array and start comaparing from 0 to n-1

int duplicate(vector<int>&arr,int n){
    sort(arr.begin(), arr.end());
    int duplicate=-1;
    // for(int i=0; i<n-1; i++){
    //     if(arr[i] == arr[i+1]){
    //         return arr[i];
    //     }
    // }
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]){
            return arr[i];
        }
    }
}

int main() {
    int n;
    cout << "Enter the n of the array: ";
    cin >> n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<"ans: "<<duplicate(arr,n);
    return 0;
}