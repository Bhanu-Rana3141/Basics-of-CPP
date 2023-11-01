#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "size : "<< size << endl;
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }cout << endl;
}

bool isSorted(int *arr, int size) {
    printArray(arr, size);

    // base case
    if(size == 0 || size == 1) {
        return true;
    }
    
    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool remainingPart = isSorted(arr + 1, size-1);
        return remainingPart;
    }
}

int main () {

    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[size];

    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    bool ans = isSorted(arr,size);

    if(ans) {
        cout << "Array is sorted";
    }
    else {
        cout << "Array is not sorted";
    }
    return 0;
}