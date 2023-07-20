#include<iostream>
using namespace std;

int countPairs(int arr[] , int size,int x){
    int count=0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] + arr[j] == x){
                count++;
            }
        }
    }
    return count;
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

    int target_sum;
    cout<<"Enter target: ";
    cin>>target_sum;

    int count = countPairs(arr,n,target_sum);
    cout<<"\nTotal pairs: "<<count;
    return 0;
}