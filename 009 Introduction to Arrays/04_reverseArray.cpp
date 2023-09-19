#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>&arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

// void reverse(vector<int>&arr, int n){
//     int i=0,j=n-1;
//     while(i<j){
//         swap(arr[i],arr[j]);
//         i++,j--;
//     }
//     return;
// }

int main() {

    int n;         
    cout<<"Enter n: ";
    cin>>n;


    vector<int>arr(n); // bad practice
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    reverse(arr.begin(), arr.end());
    // reverse(arr,n);  

    // Using inbuilt function 
    // reverse(arr,arr+n);
    printArray(arr,n);

}