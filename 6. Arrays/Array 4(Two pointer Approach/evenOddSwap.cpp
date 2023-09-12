#include<iostream>
#include<algorithm>
using namespace std;

void swapEvenOdd(int arr[] , int n){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]%2!=0 && arr[j]%2==0){
            swap(arr[i],arr[j]);
            i++,j--;
        }
        if(arr[i]%2==0){
            i++;
        } 
        if(arr[j]%2!=0){
            j--;
        }
    }
}

void odd_even_sort(int arr[],int start,int end){
    for(int i=start; i<end; i++){
        for(int j=i+1; j<end; j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter array ele: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    swapEvenOdd(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    odd_even_sort(arr,0,n/2);
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    odd_even_sort(arr,n/2,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    

    return 0;
}