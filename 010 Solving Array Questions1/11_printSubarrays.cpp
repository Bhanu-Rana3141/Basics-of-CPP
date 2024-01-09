/*
Approach 1
- using 3 loops 
TC - O(n^3) && SC - O(1)

Approach 2
- using 2 loops
TC - O(n^2) && SC - O(1)

*/

#include<iostream>
using namespace std;

void subArrayApproach1(int arr[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            for(int k=i; k<=j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

void subArrayApproach2(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int j = i;
        int k = i;
        while(j < n) { 
            if(k <= j) {
                cout << arr[k] << " ";
                k++;
            }
            else{
                j++, k=i;
                cout << endl;
            }
        }
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

    subArrayApproach1(arr, n);
    subArrayApproach2(arr, n);
    
    return 0;
}