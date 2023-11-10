#include<iostream>
using namespace std;

/*
1. Find pivot
2. Check target either in range arr[pivot] to arr[n-1] or 0 to pivot-1, if target is not present return -1

*/

//Overall TC - > O(log n) + O(log n) = O(log n)

// TC -> O(log n)
int binary_search(int arr[], int s, int e, int target){ 
    int mid = s+(e-s)/2;
    
    while(s<=e){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

// TC -> O(log n)
int pivotIndex(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
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

    int target;
    cout << "Enter target: ";
    cin >> target;
    

    // Pivot Index
    int pivot = pivotIndex(arr,n);
    
    // Searching target using pivot index
    if(target >= arr[pivot] && target <= arr[n-1]){
       cout << "target index: " << binary_search(arr,pivot,n-1,target);
    }
    else{
        cout << "target index: " << binary_search(arr,0,pivot-1,target);
    }

    return 0;
}