#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main() {
    
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<int>arr(n); 

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int k;
    cout<<"Steps to rotate: ";
    cin>>k;

    vector<int>temp(n);
    for(int i=0; i<n; i++){
        temp[(i+k) % n] = arr[i]; 
    }

    // Copying temp elements in arr
    arr = temp;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    //Brute Force Approach
/*
    printArray(arr,n);

    reverse(arr,arr+n);
    printArray(arr,n);

    reverse(arr,arr+k);
    printArray(arr,n);

    cout<<endl<<"Result: ";
    reverse(arr+k, arr+n);
    printArray(arr,n);
*/

    return 0;
}
