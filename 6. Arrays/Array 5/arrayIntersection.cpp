#include<iostream>
using namespace std;

void intersection(int arr1[],int n , int arr2[],int m){
    for(int i=0; i<n; i++){
        int count=1;
        for(int j=0; j<m; j++){
            if(arr2[j] == -1){
                continue;
            }
            else if(arr1[i] == arr2[j]){
                count++;
                arr2[j]=-1;
                break;
            }
        }
        if(count>1){
            cout<<arr1[i]<<" ";
        }
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int m;
    cout<<"Enter m: ";
    cin>>m;

    int arr1[n];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }

    int arr2[m];
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }

    intersection(arr1,n,arr2,m);

    
    return 0;
}