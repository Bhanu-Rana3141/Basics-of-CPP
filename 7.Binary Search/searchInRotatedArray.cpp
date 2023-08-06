#include<iostream>
#include<limits.h>
using namespace std;

int pivot(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int binarySearch(int arr[],int s,int e,int key){
   int mid = s+(e-s)/2;
   while(s<=e){
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] > key){
        e=mid-1;
    }
    else{
        s=mid+1;
    }
    mid=s+(e-s)/2;
   }
    return -1;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

     int key;
     cout<<"Enter key: ";
     cin>>key;

    int pivotEle = pivot(arr,n);

    if(key >= arr[pivotEle] && key<=arr[n-1]){
        cout<< binarySearch(arr,pivotEle,n-1,key);
    }else{
        cout<<binarySearch(arr,0,pivotEle-1,key);
    }
    return 0;
}