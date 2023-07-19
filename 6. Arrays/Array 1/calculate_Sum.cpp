#include<iostream>
using namespace std;

int calculateSum(int arr[] , int size){
    int sum=0;
    for(int i=0; i<size; i++){
        sum+=arr[i];
    }
    return sum;
}

int main() {
    int array[5];
   int size = sizeof(array)/sizeof(array[0]);
    cout<<"Size of Array: "<<size<<endl;
    cout<<"Enter array elements: ";

    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    int sum = calculateSum(array,size);
    cout<<"Sum: "<<sum;

    return 0;
}