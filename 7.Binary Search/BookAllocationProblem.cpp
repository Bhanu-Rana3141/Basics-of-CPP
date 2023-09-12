#include<iostream>
#include<limits.h>
using namespace std;

// USING ARRAY SPECIFICLY FOR 2 STUDENTS
int minOfMax(int arr[],int n){
 int min_sum=INT_MAX,sum_1=0;
    for(int i=0; i<n; i++){
        int max_sum=0,sum_2=0;
        sum_1 += arr[i];
        for(int j=i+1; j<n; j++){
            sum_2 += arr[j];
        }
        if(sum_1 > sum_2){
            max_sum=sum_1;
        }
        else{
            max_sum=sum_2;
        }
        if(max_sum < min_sum){
            min_sum = max_sum;
        }
    }
    return min_sum;
}

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

    //CALLING ARRAY FUNCTION
    int res = minOfMax(arr,n);
    // cout<<"Ans: "<<res;


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