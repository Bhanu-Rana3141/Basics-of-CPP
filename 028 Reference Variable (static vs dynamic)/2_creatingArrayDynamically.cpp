#include<iostream>
using namespace std;

int getSum (int *arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {

    int n;
    cin>>n;

    // creating array dynamically in heap , whole array will be stored in heap and returns address of 1st element to pointer arr in stack
    int* arr = new int[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<getSum(arr,n);
    return 0;
}