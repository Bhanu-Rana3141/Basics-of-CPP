#include<iostream>
using namespace std;

void reverse(int arr[], int n) {
    int i=0,j=n-1;

    while(i<j) {
        swap(arr[i],arr[j]);
        i++ , j--;
    }
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int arr[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    // Transpose of a matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = arr[j][i];
        }
    }
/*   Approach 2: 
      Transpose of matrix
        for(int i=0; i<size; i++) {
            for(int j=0; j<i; j++) {
               swap(matrix[i][j] , matrix[j][i]);
            }
        }
*/ 
    cout<<"Tranpose of matrix: ";
    cout<<endl;

     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    // Rotating array by 90 degrees
    for(int i=0; i<n; i++) {
        reverse(arr[i],n);
    }

    cout<<"Rotated Array: ";
    cout<<endl;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}