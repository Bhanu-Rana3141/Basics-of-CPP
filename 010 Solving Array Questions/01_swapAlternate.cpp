#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void swapAlternate(int arr[] , int n){
    for(int i=0; i<n; i+=2){
        swap(arr[i],arr[i+1]);
    }
    return;
}

int main() {
    int n;
    cout << "Enter the n of the array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    swapAlternate(arr,n);
    printArray(arr,n);

   

    return 0;
}
