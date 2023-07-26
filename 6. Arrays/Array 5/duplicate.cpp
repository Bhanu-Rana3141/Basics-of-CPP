#include<iostream>
using namespace std;

int duplicate(int arr[],int n){
    int duplicate = -1;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                duplicate=arr[i];
            }
        }
    }
    return duplicate;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = duplicate(arr,n);
    cout<<"Ans: "<<ans;

    return 0;
}