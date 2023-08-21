#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

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

void sqaureArray(int arr[],int n){
    for(int i=0; i<n; i++){
        arr[i]=arr[i]*arr[i];
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
    
    //GIVEN ARRAY
    cout<<"given array: ";
    printArray(arr,n);
    cout<<endl;

    //SQUARE ARRAY
    cout<<"Sqaure array: ";
    sqaureArray(arr,n);
    printArray(arr,n);


    cout<<"\n";

    //SORTED ARRAY
    cout<<"Sorted Array: ";
    sort(arr,n);
    printArray(arr,n);
   
    
    return 0;
}