#include<iostream>
using namespace std;

// TC -> O(log n)

int pivotIndex(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]) {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = pivotIndex(arr,n);
    cout << "Ans: " << ans;

    return 0;
}