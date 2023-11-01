#include<iostream>
using namespace std;

void print(int arr[], int size) {
    cout << "size of array: " << size << endl;
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }cout << endl;
}

int linearSearch(int arr[], int size, int k) {
    print(arr,size);

    //base case
    if(size == 0) {
        return false;
    }

    if(arr[0] == k) {
        return true;
    }
    else{
        bool remainingPart = linearSearch(arr + 1, size - 1, k);
        return remainingPart;
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

    int ans = linearSearch(arr, n, key);

   if(ans) {
    cout << "key present";
   }
   else {
    cout << "key absent";
   }
    return 0;   
}