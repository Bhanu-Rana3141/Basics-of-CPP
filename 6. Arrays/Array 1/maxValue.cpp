#include<iostream>
#include<limits.h>
using namespace std;

int maxValue(int arr[] , int size){
    int max = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] > 0){
            max=arr[i];
        }
    }
    return max;
}

int main() {
    int array[5];
    int size = sizeof(array)/sizeof(array[0]);
    cout<<"Size of Array: "<<size<<endl;

    cout<<"Enter array elements: ";
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    int max = maxValue(array,size);
    cout<<"Maximum value: " << max;


    return 0;
}