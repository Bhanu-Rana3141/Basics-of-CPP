#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "size : "<< size << endl;

    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }cout << endl;
}

int calculateSum(int arr[], int n) {
    printArray(arr,n);

    // base case
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return arr[0];
    }

    int remainingPart = calculateSum(arr+1, n-1);
    int sum = arr[0] + remainingPart;

    return sum;
}

int main () {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int sum = calculateSum(arr, n);
    
    cout << sum;
    return 0;
}