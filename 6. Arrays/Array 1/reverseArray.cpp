#include<iostream>
using namespace std;

void reverse(int arr[] , int size){
    for(int i=size-1; i>=0; i--){
        cout<<arr[i]<<" ";
    }
}

int main() {
    int array[5];
    int size = sizeof(array)/sizeof(array[0]);
    cout<<"size: "<<size<<endl;

    cout<<"Enter array ele: ";
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    reverse(array,size);

    return 0;
}