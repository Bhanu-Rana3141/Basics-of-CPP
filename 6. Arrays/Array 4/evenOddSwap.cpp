#include<iostream>
using namespace std;

void swapEvenOdd(int arr[] , int n){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]%2!=0 && arr[j]%2==0){
            swap(arr[i],arr[j]);
            i++,j--;
        }
        if(arr[i]%2==0){
            i++;
        } 
        if(arr[j]%2!=0){
            j--;
        }
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter array ele: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    swapEvenOdd(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}