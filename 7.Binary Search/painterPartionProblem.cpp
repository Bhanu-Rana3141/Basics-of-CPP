#include<iostream>
using namespace std;

bool isPossible(int arr[],int n,int k, int mid){
    int painterCount=1;
    int minRequired_time=0;

    for(int i=0; i<n; i++){
        if(arr[i] + minRequired_time <= mid){
            minRequired_time += arr[i];
        }
        else{
            painterCount++;
            if(painterCount>k || arr[i]>mid){
                return false;
            }
            minRequired_time = arr[i];
        }
    }
    return true;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter no of painters: ";
    cin>>k;

    int start=0;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    int end=sum;
    int mid=start+(end-start)/2;
    int ans=-1;

    while(start<=end){
        if(isPossible(arr,n,k,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }

    cout<<"Ans: "<<ans;
    return 0;
}