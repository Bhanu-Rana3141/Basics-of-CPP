#include<iostream>
using namespace std;

void printArray(int arr[] , int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void sortArr(int arr[] , int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void sortUsingWhileLoop(int arr[] , int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
           j--;
        }
        arr[j+1] = temp;
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
    // sortArr(arr,n);
    sortUsingWhileLoop(arr,n);
    printArray(arr,n);
    return 0;
}