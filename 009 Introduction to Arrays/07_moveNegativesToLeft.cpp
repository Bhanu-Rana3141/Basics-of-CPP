#include<iostream>
using namespace std;

void printArray(int *arr, int n) {
    
   for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
   }
   return;
}

void moveNegativesToLeft(int *arr, int n) {

    int i = 0, j = n-1;

    while(i < j) {
        if(arr[i] < 0) {
            i++;
        }
        else if(arr[j] > 0) {
            j--;
        }
        else{
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    return;
}

void moveNegative(int arr[], int n) {

    int i=0, j=0;

    while(i<n) {
        if(arr[i] < 0) {
            swap(arr[i], arr[j]);
            i++, j++;
        }
        i++;
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    moveNegativesToLeft(arr, n);
    // moveNegative(arr, n); // to print negatives in same order as input
    printArray(arr, n);
        
    return 0;
}