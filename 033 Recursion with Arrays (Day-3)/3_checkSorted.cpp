#include<iostream>
using namespace std;

// By using i as iterator
/* bool isSorted(int arr[], int n, int i) {
    // base case
    if(i >= n) {
        return true;
    }
    
    if(arr[i-1] > arr[i]) {
        return false;
    }

    isSorted(arr, n, i+1);
}
*/

bool isSorted(int arr[], int n) {
    // base case
    if(n==1) {
        return true;
    }
    
    if(arr[0] > arr[1]) {
        return false;
    }

    isSorted(arr+1, n-1);
}


int main() {
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // bool ans = isSorted(arr, n, 1);

    bool ans = isSorted(arr, n);

    if(ans) {
        cout << "Array is sorted";
    }
    else{
        cout << "Array is not sorted";
    }

    
    

    return 0;
}