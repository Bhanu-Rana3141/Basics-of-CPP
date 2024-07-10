#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest] , arr[i]);
        heapify(arr, n, largest);
    }
}

void insert(int arr[] ,int& size, int val) {

    int idx = size; 
    arr[idx] = val;

    while(idx > 0) {
        int p = (idx-1)/2;
        if(arr[idx] > arr[p]) {
            swap(arr[idx], arr[p]);
            idx = p;
        }
        else {
            return;
        }
    }
}

void del(int arr[], int& size) {

    arr[0] = arr[size-1];
    size--;
    int i = 0; 

    while(i < size) {
        int left = i*2+1;
        int right = i*2+2;

        if(left < size && arr[i] < arr[left]) {
            swap(arr[left], arr[i]);
            i = left;
        }
        else if(right < size && arr[i] < arr[right]) {
            swap(arr[i], arr[right]);
            i = right;
        }
        else {
            return;
        }
    }
}

void print(int *arr, int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{   
    int n = 5;
    int arr[] = {4,1,3,9,7};
    
    for(int i = n/2; i>=0; i--) {
        heapify(arr, n, i);
    }

    insert(arr, n, 12);
    print(arr, n);
    del(arr, n);
    print(arr, n);

    return 0;
}