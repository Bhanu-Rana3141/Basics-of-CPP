#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

     int sum=0;
    for(int i=0; i<n; i++){
        if(i==0){
            sum+=arr[i];
            continue;
        }
        else{
            for(int j=i; j<=i; j++){
                sum+=arr[i];
            }
        }
        arr[i]=sum;
    }
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}