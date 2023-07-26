#include<iostream>
using namespace std;

void frequency(int arr[],int n){
    for(int i=0; i<n; i++){
        int count=1;
        for(int j=i+1; j<n; j++){
            if(arr[i] == -1){
                break;
            }
            else if(arr[i]==arr[j]){
                count++;
                arr[j]=-1;
            }
        }
        if(arr[i]>0){
            cout<<arr[i]<<" : "<<count<<endl;
        }
    }
}

int main() {
    int  n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    frequency(arr,n);
    return 0;
}