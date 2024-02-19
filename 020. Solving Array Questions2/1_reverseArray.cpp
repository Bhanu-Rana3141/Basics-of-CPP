#include<iostream>
using namespace std;

void printArray(int arr[] , int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void reverse(int arr[] , int n){
    int i=0,j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++,j--;
    }
    return;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
   
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Array: ";
    printArray(arr,n);
    cout << endl;

    reverse(arr,n);
    
    cout << "Reverse: ";
    printArray(arr,n);

    
    return 0;
}