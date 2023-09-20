#include<iostream>
using namespace std;

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

/* 
    Approach 1 -> time complexity O(n*m)
    int row=0;
    for(int col = 0; col<m; col++) {
        if(row <= 0){
            for(row=0; row<n; row++) {
                cout<<arr[row][col];
            }
        }
        else{
            for(row=n-1; row>=0; row--){
                cout<<arr[row][col]<<" ";
            }
        }
    }
*/  

// Approach 2 -> O(n*m)
    for(int col = 0; col<m; col++){
        if(col % 2 !=0){
            for(int row = n-1; row>=0; row--) {
                cout<<arr[row][col]<<" ";
            }
        }
        else{
            for(int row=0; row<n; row++){
                cout<<arr[row][col]<<" ";
            }
        }
    }
    return 0;
}