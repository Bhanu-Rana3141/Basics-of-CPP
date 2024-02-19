#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    // step 1 : choose a pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    // step 2 : place pivot element at it's right position
    int count = 0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivotElement) {
            count++;
        }
    }

    int rightIndex = s + count;
    swap(arr[rightIndex], arr[pivotIndex]);
    pivotIndex = rightIndex;

    // step 3 : left part should have smaller elements and right part should have greater elements
    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] < pivotElement) {
            i++;
        }
        while(arr[j] > pivotElement) {
            j--;
        }

        // After this 2 cases can occur
        // 1. elements found to swap
        // 2. no need to swap
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    
    if(s >= e) {
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);

    quickSort(arr, p+1, e);
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int s = 0;
    int e = n-1;

    quickSort(arr, s, e);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}