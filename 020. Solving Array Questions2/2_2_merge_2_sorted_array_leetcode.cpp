#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force Approach-> merge array and sort it. TC -> O(n log n) 

void printArray(vector<int>&arr1){
    for(int i=0; i<arr1.size(); i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}

// TC -> O(n+m)
void merge(vector<int>&arr1 , vector<int>&arr2, int m , int n){
    
    vector<int>ans;

    int i=0, j=0;
    while(i<m && j<n) {
        if(arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<m) {
        ans.push_back(arr1[i]);
        i++;
    } 
    while(j<n) {
        ans.push_back(arr2[j]);
        j++;
    }

    arr1 = ans;
}

int main() {
    
    int m;
    cout << "Enter m: ";
    cin >> m;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter arr1 elements: ";
    vector<int>arr1(m+n);
    for(int i=0; i<m+n; i++){
        cin >> arr1[i];
    }

    cout << "Enter arr2 elements: ";
    vector<int>arr2(n);
    for(int i=0; i<n; i++){
        cin >> arr2[i];
    }
    
    merge(arr1,arr2,m,n);

    printArray(arr1); 
    
    return 0;
}