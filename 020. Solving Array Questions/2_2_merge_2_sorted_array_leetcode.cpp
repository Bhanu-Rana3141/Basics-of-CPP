#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>&arr1){
    for(int i=0; i<arr1.size(); i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int>&arr1 , vector<int>&arr2, int m , int n){
    int j=0; 
    for(int i=m; i<arr1.size(); i++){
        arr1[i] = arr2[j++];
    }
}

int main() {
    
    int m;
    cout<<"Enter m: ";
    cin>>m;

    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter arr1 elements: ";
    vector<int>arr1(m+n);
    for(int i=0; i<m+n; i++){
        cin>>arr1[i];
    }

    cout<<"Enter arr2 elements: ";
    vector<int>arr2(n);
    for(int i=0; i<n; i++){
        cin>>arr2[i];
    }
    
    merge(arr1,arr2,m,n);

    // Before sorting
    printArray(arr1); 

    sort(arr1.begin() , arr1.end());

    // After sorting
    printArray(arr1); 
    return 0;
}