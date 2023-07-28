#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void sort(int arr[],int n){
   int zeroCount=0;
   int oneCount=0;
    
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            zeroCount++;
        }
        else if(arr[i] == 1){
            oneCount++;
        }
    }
        
    int j=0;
    for(int i=0; i<n; i++){
        if(i<zeroCount){
            arr[i]=0;
        }
        else if(j<oneCount){
            arr[i]=1;
            j++;
        }
        else{
            arr[i]=2;
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

   
    sort(arr,n);
    printArray(arr,n);
    return 0;
}