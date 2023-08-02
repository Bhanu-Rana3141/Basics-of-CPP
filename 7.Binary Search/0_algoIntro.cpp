#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int start = 0;
    int end = n-1;

    int  mid = start+(end-start/2);

    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        if(key>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }   
        mid = start+(end-start/2);
    }
    return -1;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter key: ";
    cin>>key;


    int index = binarySearch(arr,n,key);
    cout<<"Index of key is: "<<index;
    return 0;
}