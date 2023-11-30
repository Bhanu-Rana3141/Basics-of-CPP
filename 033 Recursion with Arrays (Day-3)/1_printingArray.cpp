#include<iostream>
using namespace std;

void print(int arr[], int n) {
    // base case
    if(n == 0) {
        return;
    }
    cout << arr[0] << " "; 
    print(arr+1, n-1);
}

void print(int arr[], int n, int i) {
    if(i >= n) {
        return;
    }
    print(arr, n, i+1);
    cout << arr[i] << " ";
}

int main() {

    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr,n);
    cout << endl;

    int i=0;
    print(arr, n, i);
    
    return 0;
}