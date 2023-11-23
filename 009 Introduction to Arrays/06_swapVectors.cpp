#include <iostream>
#include<vector>
using namespace std;

void printArray(vector<int>&arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int n;
    cout << "Ente n : ";
    cin >> n;

    cout << "arr1 elements: ";
    vector<int>arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "arr2 elements: ";
    vector<int>arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    swap(arr1,arr2);

    cout << "arr1: ";
    printArray(arr1);
    
    cout << "arr2: ";
    printArray(arr2);

    return 0;
}
