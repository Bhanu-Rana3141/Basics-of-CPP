#include<iostream>
using namespace std;


/* 
Worst case or average case TC -> O(n^2)
Best Case (array already sorted) -> O(n)
*/

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void optimised_approach(int arr[] , int n){
    for(int i=0; i<n; i++) {
        bool flag = true;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if(flag == true){
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // bubble_sort(arr,n);

    optimised_approach(arr,n);

    printArray(arr,n);

    return 0;
}