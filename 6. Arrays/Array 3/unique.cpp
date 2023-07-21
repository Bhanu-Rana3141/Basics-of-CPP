#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array ele: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                arr[i]=arr[j]=-1;
            }
        }
    }
    int unique=0;
    for(int i=0; i<n; i++){
       if(arr[i]>0){
        unique=arr[i];
       }
    }

    cout<<"Unique no: "<<unique;

    return 0;
}