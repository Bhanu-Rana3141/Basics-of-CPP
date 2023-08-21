#include<iostream>
using namespace std;

int peakElement(int arr[],int n){
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    int ans=-1;

    while(start<end){
        if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid;
        }
        else{
            
        }
        mid = start+(end-start)/2;
    }
    return ans;
}



int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

   
    return 0;
}