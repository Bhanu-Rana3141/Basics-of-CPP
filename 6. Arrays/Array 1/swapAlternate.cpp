#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void swap(int arr[],int n){
    for(int i=0; i<n; i+=2){
        int temp = arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array ele: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    printArray(arr,n);
    cout<<endl;
    cout<<"swapped array: ";
    swap(arr,n);
    printArray(arr,n);
    return 0;
}