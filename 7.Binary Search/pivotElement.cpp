#include<iostream>
#include<limits.h>
using namespace std;

//Time Complexity - O(log n)
int pivot(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid] > arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

//Time Complexity - O(n)
int linearSearch_Pivot(int arr[],int n){  
    int min = INT_MAX;
    int min_index=-1;
    for(int i=0; i<n; i++){
        if(arr[i]<min){
            min=arr[i];
            min_index=i;
        }
    }
    return min_index;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Index of pivot ele: "<<pivot(arr,n)<<endl;
    cout<<"min index: "<<linearSearch_Pivot(arr,n);

    return 0;
}