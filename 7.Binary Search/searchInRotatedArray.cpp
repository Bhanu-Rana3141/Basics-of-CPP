#include<iostream>
using namespace std;

int pivotIndex(int arr[],int n){
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;

    while(start<end){
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return end;
}

int binarySearch(int arr[],int start,int end,int target){
    int mid = start+(end-start)/2;

    while(start<=end){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
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

    int target;
    cout<<"Enter target: ";
    cin>>target;

    cout<<"Pivot Index: ";
    int pivot = pivotIndex(arr,n);
    cout<<pivot<<endl;

    if(target>= arr[pivot] && target <= arr[n-1]){
       cout<<"Ans: "<< binarySearch(arr,pivot,n-1,target);
    }
    else{
       cout<< "Ans: "<< binarySearch(arr,0,pivot-1,target);
    }   
    return 0;
}