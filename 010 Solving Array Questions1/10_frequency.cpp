#include<iostream>
using namespace std;

void using_nested_loops(int arr[], int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] == -1) continue;
        int count = 1;
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]){
                count++;
                arr[j] = -1;
            }
        }
        cout << arr[i] << " : " << count << endl;
    }
}

void using_hashing(int *arr, int n) {
    int hash[n] = {0};
    for(int i=0; i<n; i++) {
        hash[arr[i]]++;
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " : " << hash[arr[i]] << endl;
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

    // using_nested_loops(arr, n);  

    using_hashing(arr, n);

    return 0;
}