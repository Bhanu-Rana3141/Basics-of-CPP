#include<iostream>
using namespace std;

void duplicate(int arr[],int n){
    for(int i=0; i<n; i++){
        int count=1;
        for(int j=i+1; j<n; j++){
            if(arr[i]==-1){
                break;
            }
            else if(arr[i] == arr[j]){
                count++;
                arr[j]=-1;
            }
        }
        if(count>1){
            cout<<arr[i]<<" ";
        }
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    duplicate(arr,n);
    return 0;
}