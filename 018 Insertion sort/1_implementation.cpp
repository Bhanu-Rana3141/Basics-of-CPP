#include<iostream>
using namespace std;

void printArray(int arr[], int n) {

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void insertion_sort(int arr[], int n) {

    int k = 1;
    for(int i=1; i<n-1; i++) {
        k=i;
        for(int j=i-1; j>=0; j--) {
            if(arr[k] < arr[j]) {
                swap(arr[k], arr[j]);
                k--;
            }
            else{
                break;
            } 
        }
    }
}

void using_while_loop(int arr[], int n){

    for(int i=1; i<n; i++) {
        int k = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > k) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
}

int main() {
            
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // insertion_sort(arr, n);

    using_while_loop(arr, n);

    printArray(arr, n);
    return 0;
}