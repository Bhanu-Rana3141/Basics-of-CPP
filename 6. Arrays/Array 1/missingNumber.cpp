#include<iostream>
using namespace std;

void sortArray(int arr[] , int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int missingNumber(int arr[] , int n){
    for(int i=0; i<n; i++){
        if(arr[i] != i){
            return i;
        }
    }
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int array[n];
    cout<<"Enter array ele: ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    sortArray(array,n);

     for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }

    int number = missingNumber(array,n);
    cout<<"\nmissing number: "<<number;
    return 0;
}