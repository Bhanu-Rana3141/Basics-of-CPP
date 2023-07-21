#include<iostream>
#include<limits.h>
using namespace std;

int secondLargest(int arr[] , int n){
    int max=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max=arr[i];
        }
    }

    int secondMax=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i] > secondMax && arr[i]<max){
            secondMax=arr[i];
        }
    }
    return secondMax;

}

int main() {
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array ele: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int secondMax = secondLargest(arr,n);
    cout<<"Second largest: "<<secondMax;
    
}