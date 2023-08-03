#include<iostream>
using namespace std;

int firstOccurence(int arr[],int n,int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int lastOccurence(int arr[],int n,int key){
    for(int i=n-1; i>=0; i--){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}


int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter key: ";
    cin>>key;

    cout<<firstOccurence(arr,n,key)<<" "<<lastOccurence(arr,n,key);

}