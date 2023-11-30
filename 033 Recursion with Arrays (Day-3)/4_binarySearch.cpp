#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
    // base case 
    // case 1 -> if key not found
    if(s > e) {
        return -1;
    }

    int mid = s+(e-s)/2;

    // case 2 -> key found
    if(arr[mid] == key) {
        return mid;
    }

    // arr[mid] < key -> search in right part
    if(arr[mid] < key) {
        return binarySearch(arr, mid+1, e, key);
    }
    // arr[mid] > left m search karo
    else{ 
        return binarySearch(arr, s, mid-1, key);
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

    int key;
    cout << "Enter key: ";
    cin >> key;

    int s = 0;
    int e = n-1;

    int ans = binarySearch(arr, s, e, key);

    cout << "Key present at index: " << ans;
    
    return 0;
}