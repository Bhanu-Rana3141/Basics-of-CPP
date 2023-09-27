#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the n of the array: ";
    cin >> n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout<<"Enter target: ";
    cin>>target;

    vector<int>ans;

    int tripletCount = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == target){
                    tripletCount++;
                    cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
                }
            }
        }
    }
    cout<<"triplet count: "<<tripletCount;
    return 0;
}
