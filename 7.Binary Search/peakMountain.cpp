#include<iostream>
using namespace std;

int peakMountainELement(int arr[],int n){

    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;

    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            end=mid;
        }
        mid = start+(end-start)/2;
    }
    return start;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Index of mid: "<<peakMountainELement(arr,n);

    return 0;
}