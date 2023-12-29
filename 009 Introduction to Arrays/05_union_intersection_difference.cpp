#include<iostream>
#include<vector>
using namespace std;

void printArr(vector<int>& arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

void intersection(vector<int>& arr1, int n, vector<int>& arr2, int m, vector<int>& ans) {

    int i=0, j=0;
    while(i < n && j < m) {
        if(arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++, j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else{
            j++;
        }
    }
}

void unionArr(vector<int>& arr1, int n, vector<int>& arr2, int m, vector<int>& ans) {

    int i=0, j=0;
    while(i<n && j<m) {
        if(arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++, j++;
        }
        else if(arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    } 
    while(i < n) {
        ans.push_back(arr1[i]);
        i++;
    }
    while(j < m) {
        ans.push_back(arr2[j]);
        j++;
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr1(n);
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter m: ";
    cin >> m;

    vector<int>arr2(m);;
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    vector<int>ans;

    if(choice == 1) {
        intersection(arr1, n, arr2, m, ans);
    }
    else if(choice == 2) {
        unionArr(arr1, n, arr2, m, ans);
    }

    printArr(ans);
    
    return 0;
}