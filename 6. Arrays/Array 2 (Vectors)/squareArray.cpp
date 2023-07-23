#include<iostream>
using namespace std;

void sort(int arr[],int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void squareArray(int arr[],int n, int squareArr[]){
    for(int i=0; i<n; i++){
        squareArr[i]=arr[i]*arr[i];
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

    int square[n];
    
    squareArray(arr,n,square);

    for(int i=0; i<n; i++){
        cout<<square[i]<<" ";
    }

    cout<<"\n\nSorted Array: ";
    sort(square,n);
    for(int i=0; i<n; i++){
        cout<<square[i]<<" ";
    }
    return 0;
}