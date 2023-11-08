#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {

    int pivot = arr[s];

    int count = 0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }

    // place pivot element at right place
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    // sort left and right part
    int i=0, j=e;
    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++, e--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {

    // base case
    if(s >= e) {
        return;
    }

    // partition
    int p = partition(arr, s, e);

    // sort left part
    quickSort(arr, 0, p-1);

    // sort right part
    quickSort(arr, p+1, e);

}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}