#include <iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cout << "Enter the n of the array: ";
    cin >> n;

    vector<int>arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout<<"Enter target: ";
    cin>>target;

    vector<int>ans;

    int pairsCount = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                pairsCount++;
                if(arr[i] < arr[j]){
                    cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
                }
                else{
                    cout << "(" << arr[j] << "," << arr[i] << ")" << endl;
                }
            }
        }
    }
    
    cout << "Pair count: " << pairsCount;
    
    return 0;
}
