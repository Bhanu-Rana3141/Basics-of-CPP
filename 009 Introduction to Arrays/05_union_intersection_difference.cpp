#include<iostream>
#include<vector>
using namespace std;

void intersection(int arr1[], int arr2[], int n, int m, int ans[]) {

    int i=0, j=0, k=0;
    while(i<n && j<m) {
        if(arr1[i] == arr2[j]) {
            ans[k] = arr1[i];
            i++,j++,k++;
        }
        else if(arr[i] < arr[j]) {
            i++;
        }
        else{
            j++;
        }
    } 

    while(i<n) {
        ans[k] = arr1[i];
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter m: ";
    cin >> m;

    int arr[m];
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    // vector<int>ans;
    int ans[];

    if(choice == 1) {
        intersection(arr1, arr2, n, ans);
    }
    else if(choice == 2) {
        unionOfArrays(arr, arr2,n, ans);
    }
    
    return 0;
}