#include<iostream>
#include<limits.h>
using namespace std;

int max(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}

int min(int arr[] , int n){
    int mini = INT_MAX;
    for(int i=0; i<n; i++){
        mini = min(mini,arr[i]);
    }
    return mini;
}

int main() {

    int n;         
    cout << "Enter n: ";
    cin >> n;


    int arr[n]; // bad practice
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int maximum = max(arr,n);
    int minimum = min(arr,n);

    cout << "Max: " << maximum << endl;
    cout << "Min: " << minimum;
}