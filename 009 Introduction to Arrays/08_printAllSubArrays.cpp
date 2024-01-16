#include<iostream>
using namespace std;

// using 3 loops -> O(N^3)
// void printSubArrays(int arr[], int n) {
//     for(int i=0; i<n; i++) {
//         for(int j=i; j<n; j++) {
//             for(int k=i; k<=j; k++) {
//                 cout << arr[k] << " ";
//             }
//             cout << endl;
//         }
//     }
// }

// using 2 loops -> O(N^2)
void printSubArrays(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int j = i;
        int k = i;
        while(j < n) {
            if(k <= j) {
                cout << arr[k] << " ";
                k++;
            }
            else {
                cout << endl;
                j++;
                k = i;
            }
        }
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    printSubArrays(arr, n);
    
    return 0;
}