#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

// Time Complexity - O(n^2)
void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// But in best case if array is already sorted ,we will use a boolean variable 
// Optimised Approach -> TC - O(n)
void optimised_approach(int arr[] , int n){
    for(int i=0; i<n; i++) {
        bool flag = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(flag == false){
            break;
        }
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // bubble_sort(arr,n);
    optimised_approach(arr,n);
    printArray(arr,n);

    return 0;
}