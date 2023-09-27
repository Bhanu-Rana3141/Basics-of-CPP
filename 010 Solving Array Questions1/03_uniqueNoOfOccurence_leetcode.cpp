#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

void printArray(vector<int>arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }cout<<endl;
}


int main() {
    int n;
    cout << "Enter the n of the array: ";
    cin >> n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int>result;

    for(int i=0; i<n; i++){
        if(arr[i] == INT_MIN){
            arr.erase(arr.begin()+i);
        }
        int count=1;
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
                arr[j] = INT_MIN;
            }
        }
        result.push_back(count);
    }

    printArray(arr,n);
    printArray(result,n);
    
    return 0;
}