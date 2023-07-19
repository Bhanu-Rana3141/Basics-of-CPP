#include<iostream>
using namespace std;

int minSum(int arr[] , int size){
    int min=100;
    for(int i=0; i<size; i++){
        if(arr[i] < min){
            min=arr[i];
        }
    }
    return min;
}

int main(){
    int array1[5];
    int size = sizeof(array1)/sizeof(array1[0]);
    cout<<"size: "<<size<<endl;

    cout<<"Enter array1 ele: ";
    for(int i=0; i<size; i++){
        cin>>array1[i];
    }

    int array1_min = minSum(array1,size);


    int array2[5];
    cout<<"Enter array2 ele: ";
    for(int i=0; i<size; i++){
        cin>>array2[i];
    }

    int array2_min = minSum(array2,size);
    cout<<"Min sum: "<<array1_min+array2_min;

    return 0;
}