#include<iostream>
#include<vector>
using namespace std;

// Time complexity -> O(log(row*col))

int main() {

    int n; //row size;
    cout<<"Enter row size: ";
    cin>>n;

    int m; //col size
    cout<<"Enter col size: ";
    cin>>m;

    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout << endl;

    int target;
    cout<<"Enter target: ";
    cin>>target;

 /*  linear approach   --> O(m*n)
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == target) {
                cout<<"true";
                return 0;
            }
        }
    }
    cout<<"False";
*/

    // Binary search Approach   --> O(log(n*m))

    int s = 0;
    int e = n*m-1;
    int mid = s+(e-s)/2;

    while(s<=e) {
        int element = arr[mid/m][mid%m];  // m -> no of cols

        if(element == target) {
            cout<<"True";
            return 0;
        }
        else if(element > target) {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    } 
    cout<<"False";
    return 0;
}