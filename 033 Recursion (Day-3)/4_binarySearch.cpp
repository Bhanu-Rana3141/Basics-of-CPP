#include<iostream>
using namespace std;

void print(int arr[], int s, int e) {
    for(int i=s; i<=e; i++) {
        cout << arr[i] << " ";
    }cout << endl;
}

int binarySearch(int arr[], int s, int e, int k) {
    cout << endl;
    print(arr,s,e);

    // base case 
    // If element not found
    if(s>e) {
        return -1;
    } 

    int mid = s+(e-s)/2;
    cout << "value of mid: " << arr[mid] << endl;

    // if element found
    if(arr[mid] == k) {
        return mid;
    }

    if(arr[mid] < k) {
        binarySearch(arr, mid+1, e, k);
    }
    else{
        binarySearch(arr, s, mid-1, k);
    }   
}

int main () {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i]; 
    }

    int key;
    cout << "Enter key : ";
    cin >> key;

    cout << "present or not : " << binarySearch(arr, 0, n-1, key);
    return 0;   
}