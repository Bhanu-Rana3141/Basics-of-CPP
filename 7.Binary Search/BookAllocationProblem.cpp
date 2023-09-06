#include<iostream>
using namespace std;

bool isPossible(int arr[],int n,int m,int mid){
    int studentCount=1;
    int pageSum=0;

    for(int i=0; i<n; i++){
        if(arr[i]+pageSum <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int m;
    cout<<"Enter m: ";
    cin>>m;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int start=0;
    //Calculating sum for end index
    int sum=0;
    for(int i=0; i<n; i++){ 
        sum+=arr[i];
    }
    int end=sum;
    int mid = start+(end-start)/2;
    int ans=-1;

    while(start<=end){
        if(isPossible(arr,n,m,mid)){
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