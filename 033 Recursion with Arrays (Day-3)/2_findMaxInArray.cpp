#include<iostream>
#include<limits.h>
using namespace std;

void findMax(int arr[], int n, int i, int& max) {
    // base case
    if(i >= n) {
        return;
    }
    // 1 case solve kardo
    if(arr[i] > max) {
        max = arr[i];
    }
    // baaki recursion sambhal lega
    findMax(arr, n, i+1, max);
}

void findMin(int arr[], int n, int& min) {
    //base case
    if(n == 0) {
        return;
    }
    if(arr[0] < min) {
        min = arr[0];
    }
    findMin(arr+1, n-1, min);
}

int main() {

    int arr[] = {10,20,30,40,50,66,78,33};

    int n = 8;
    int i=0;
    int max = INT_MIN;

    findMax(arr, n, i, max);
    cout << "maximum : " << max << endl;

    int min = INT_MAX;
    findMin(arr, n, min);
    cout << "minimum : " << min;

    return 0;
}