#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>&arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//TC -> O(n * log n)
void approach_1_finding_duplicates(vector<int>&arr, int n) {
    sort(arr.begin(), arr.end());  
    printArray(arr);

    vector<int>duplicates; 

    for(int i=0; i<n-1; i++) {
        if(arr[i] == arr[i+1]) {
            duplicates.push_back(arr[i]);
        }
    }
    printArray(duplicates);
}


// TC -> O(n^2)
void approach_2_finding_duplicates(vector<int>&arr, int n) {

    vector<int>duplicates; 

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[j] == -1) {
                break;
            }
            if(arr[i] == arr[j]) {  
                duplicates.push_back(arr[i]);
                arr[j] = -1;
                break;
            }
        }
    }
    cout << "Duplicates: ";
    printArray(duplicates);
}


// TC -> O(n)
void approach_3_finding_duplicates(vector<int>&arr, int n) {
    
    vector<int>duplicates;
    int i=0, j=n-1;
    while(i<j) {
        if(arr[i] == arr[j]) {
            duplicates.push_back(arr[i]);
        }
        j--;
        if(i==j) {
            i++, j=n-1;
        }
    }
}

int main () {
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    
    // Approach - 1 -> sort array and find duplicates in vector and storing them in a new vector
    // approach_1_finding_duplicates(arr,n);

    // Approach -2 -> using 2 loops
    // approach_2_finding_duplicates(arr,n);
   

    // Approach - 3 -> using 2 pointer approach
    approach_3_finding_duplicates(arr,n);

    return 0;
}